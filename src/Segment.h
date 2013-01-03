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
 * File Name:   Segment.h
 * Description: This file contains definitions for 
 *                      up��
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-28                 jianmink                  Initial creation ...                        
 ***********************************************************************/


#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "BitString.h"
class Segments
{

BitString str;

public:
int L;
int C;
int B_;
int Z;

int K1;  //K+
int K2;  //K_

int C1;   //C+
int C2;   //C_

int F;

char* c;
int* Kr;

public:
	Segments();
	~Segments();
	void setMaxBlockSizeInBit(int z){Z=z;}
	int getMaxBlockSizeInBit(){return Z;}
	void prepare(int);
	Segments& prepare(BitString);

	int getCRCLen(){return L;}
	int getNumSegments(){return C;}
	int getNumBitsAfter(){return B_;}

	int getKPlus(){return K1;}
	int getKMinus(){return K2;}
	void encode(char filler='0');

	BitString toString(char*, int);
	BitString toString(int);

private:
	void calculate();

	void encodeBlockCRC(char*, int, int);
};


#endif /* SEGMENT_H_ */
