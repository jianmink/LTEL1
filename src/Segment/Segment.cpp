/***********************************************************************
 *
 *  Copyright (c) 2012 Alcatel-Lucent Technologies.
 *  All rights reserved.
 *
 *  ALL RIGHTS ARE RESERVED BY ALCATEL-LUCENT TECHNOLOGIES.
 *  ACCESS TO THIS SOURCE CODE IS STRICTLY RESTRICTED
 *  UNDER CONTRACT. THIS CODE IS TO BE KEPT STRICTLY
 *  CONFIDENTIAL. UNAUTHORIZED MODIFICATIONS OF THIS FILE
 *  WILL VOID YOUR SUPPORT CONTRACT WITH ALCATEL-LUCENT
 *  TECHNOLOGIES.  IF SUCH MODIFICATIONS ARE FOR THE
 *  PURPOSE OF CIRCUMVENTING LICENSING LIMITATIONS, LEGAL
 *  ACTION MAY RESULT.
 *
 ***********************************************************************
 *
 * File Name:   Segment.cpp
 * Description: This file contains definitions for 
 *                      Code block segmentation and code block CRC attachment
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-28                 jianmink                  Initial creation ...                        
 ***********************************************************************/

#include "TurboCode.h"
#include "Segment.h"
#include "CRC.h"

#include <iostream>
using namespace std;

#include "MyMath.h"

Segments::Segments()
{
	//config 
	gpLen=0;
	maxSegmentSize=6144;
	

	//input
	inputStr="";

	//output 
	outputBits=NULL;
	segmentLenArray=NULL;
	
	//state
	segmentNum=0;
	bigSegmentNum=0;
	smallSegmentNum=0;
	
	bitNumWithoutFiller=0;
	fillerNum=0;

	bigSegmentSize=0;
	smallSegmentSize=0;

}

Segments::~Segments()
{
	if(outputBits)
		delete[] outputBits;
	if(segmentLenArray)
		delete[] segmentLenArray;
}

Segments& Segments::prepare(BitString b)
{
	inputStr=b;
	prepare(inputStr.toString().length());
	return *this;
}

void Segments::prepare(int B)
{
	if(B<=maxSegmentSize)
	{
		gpLen=0;
		segmentNum=1;
		bitNumWithoutFiller=B;
	}
	else
	{
		gpLen=24;
		segmentNum=ceil((float)B/(maxSegmentSize-gpLen));
		bitNumWithoutFiller=B+segmentNum*gpLen;
	}

	calculate();
}

void Segments::calculate()
{

	int j=0;
	while(gTurboCodeTable[j].i
			&& segmentNum*gTurboCodeTable[j].k<bitNumWithoutFiller)
	{
		j++;
	}

	bigSegmentSize=gTurboCodeTable[j].k;
	smallSegmentSize=gTurboCodeTable[j-1].k;

	if(segmentNum==1)
	{
		smallSegmentSize=0;
		bigSegmentNum=1;
		smallSegmentNum=0;
	}
	else
	{
		int delta=bigSegmentSize-smallSegmentSize;
		smallSegmentNum=floar((float)(segmentNum*bigSegmentSize-bitNumWithoutFiller)/delta);
		bigSegmentNum=segmentNum-smallSegmentNum;
	}

	fillerNum=smallSegmentNum*smallSegmentSize+bigSegmentNum*bigSegmentSize -bitNumWithoutFiller;
}

void Segments::encode(char filler)
{
	outputBits= new char[segmentNum*bigSegmentSize];
	segmentLenArray= new int[segmentNum];

	int k;
	for(k=0; k<fillerNum; k++)
	{
		outputBits[k]=filler;
	}

	int s=0;

	for(int r=0; r<segmentNum; r++)
	{
		if(r<smallSegmentNum)
			segmentLenArray[r]=smallSegmentSize;
		else
			segmentLenArray[r]=bigSegmentSize;


		while(k<segmentLenArray[r]-gpLen)
		{
			outputBits[r*bigSegmentSize+k]=inputStr.toString()[s];
			k++;
			s++;
		}

		if(segmentNum>1)
		{
			encodeBlockCRC((char*)(&outputBits[r*bigSegmentSize+0]),k);
		}

		k=0;
	}
}

void Segments::encodeBlockCRC(char* c, int len)
{
	CRC crc;
	crc.setGp(CRC::GCRC24B);

	BitString bitStr= toString(c, len);

	BitString crcResult=crc.encode(&bitStr);

	int end=len+crcResult.length();
	for(int i=len; i<end; i++)
		c[i]=crcResult[i+gpLen-end];
}

BitString Segments::toString(char* c, int len)
{
	BitString bitStr="";
	for(int i=0; i<len; i++)
	{
		string str;
		str.append(1,c[i]);
		bitStr=bitStr+str;
	}

	return bitStr;
}

BitString Segments::toString(int r)
{
	int offset =0;
	for(int i=0; i<r; i++)
		offset+=segmentLenArray[i];

	return toString(outputBits+offset, segmentLenArray[r]);
}


