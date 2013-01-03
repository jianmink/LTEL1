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
	L=0;
	C=0;
	B_=0;
	K1=0;
	K2=0;

	c=NULL;
	Kr=NULL;
}

Segments::~Segments()
{
	if(c)
		delete[] c;
	if(Kr)
		delete[] Kr;
}

Segments& Segments::prepare(BitString b)
{
	str=b;
	prepare(str.toString().length());
	return *this;
}

void Segments::prepare(int B)
{
	if(B<=Z)
	{
		L=0;
		C=1;
		B_=B;
	}
	else
	{
		L=24;
		C=ceil((float)B/(Z-L));
		B_=B+C*L;
	}

	calculate();
}

void Segments::calculate()
{

	int j=0;
	while(gTurboCodeTable[j].i
			&& C*gTurboCodeTable[j].k<B_)
	{
		j++;
	}

	K1=gTurboCodeTable[j].k;
	K2=gTurboCodeTable[j-1].k;

	if(C==1)
	{
		K2=0;
		C1=1;
		C2=0;
	}
	else
	{
		int deltaK=K1-K2;
		C2=floar((float)(C*K1-B_)/deltaK);
		C1=C-C2;
	}

	F=C2*K2+C1*K1 -B_;
}

void Segments::encode(char filler)
{
	c= new char[C*K1];
	Kr= new int[C];

	int k;
	for(k=0; k<F; k++)
	{
		c[k]=filler;
	}

	int s=0;

	for(int r=0; r<C; r++)
	{
		if(r<C2)
			Kr[r]=K2;
		else
			Kr[r]=K1;


		while(k<Kr[r]-L)
		{
			c[r*K1+k]=str.toString()[s];
			k++;
			s++;
		}

		if(C>1)
		{
			encodeBlockCRC((char*)(&c[r*K1+0]),k,Kr[r]);
		}

		k=0;
	}
}

void Segments::encodeBlockCRC(char* c, int start, int end)
{
	CRC crc;
	crc.setGp(CRC::GCRC24B); //gcrc24b

	BitString bitStr= toString(c, start);

	BitString p=crc.encode(&bitStr);

	for(int k=start; k<end; k++)
		c[k]=p[k+L-end];
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
		offset+=Kr[i];

	return toString(c+offset, Kr[r]);
}


