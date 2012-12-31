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
 *                      up¡­
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-28                 jianmink                  Initial creation ...                        
 ***********************************************************************/


#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "BitString.h"
class Segment
{
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
int* K;

public:
	Segment();
	~Segment();
	void setZ(int z){Z=z;}
	void prepare(int);
	int getL(){return L;}
	int getC(){return C;}
	int getB_(){return B_;}

	int getK1(){return K1;}
	void encode(BitString, char filler='0');

private:
	void calculate();

	void encodeBlockCRC(char*, int, int);
};


#endif /* SEGMENT_H_ */
