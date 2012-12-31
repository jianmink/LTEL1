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
 *                      up¡­
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


int ceil(float v)
{
	int n=(int)v;
	if(v-n!=0)
		return n+1;

	return n;
}

int floar(float v)
{
	return (int)v;
}


Segment::Segment()
{
	L=0;
	C=0;
	B_=0;
	K1=0;
	K2=0;

	c=NULL;
	K=NULL;
}

Segment::~Segment()
{
	if(c)
		delete[] c;
	if(K)
		delete[] K;
}

void Segment::prepare(int B)
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

void Segment::calculate()
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

void Segment::encode(BitString b_,char filler)
{
	c= new char[C*K1];
	K= new int[C];

	int k;
	for(k=0; k<F; k++)
	{
		c[k]=filler;
	}

	int s=0;

	for(int r=0; r<C; r++)
	{
		if(r<C1)
			K[r]=K2;
		else
			K[r]=K1;


		while(k<K[r]-L)
		{
			c[r*K1+k]=b_.toString()[s];
			k++;
			s++;
		}

		if(C>1)
		{
			encodeBlockCRC((char*)(&c[r*K1+0]),k,K[r]);
		}

		k=0;
	}
}

void Segment::encodeBlockCRC(char* c, int start, int end)
{
	CRC crc;
	crc.setGp(CRC::GCRC24B); //gcrc24b

	BitString cStr="";
	for(int i=0; i<start; i++)
	{
		string str;
		str.append(1,c[i]);
		cStr=cStr+str;
	}

	BitString p=crc.encode(&cStr);

	for(int k=start; k<end; k++)
		c[k]=p[k+L-end];
}




