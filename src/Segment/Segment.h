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
class Segments
{

BitString inputStr;

public:
int gpLen;
int segmentNum;
int bitNumWithoutFiller;
int maxSegmentSize;

int bigSegmentSize;  //K+
int smallSegmentSize;  //K_

int bigSegmentNum;   //C+
int smallSegmentNum;   //C_

int fillerNum;

char* outputBits;
int* segmentLenArray;

public:
	Segments();
	~Segments();
	void setMaxBlockSizeInBit(int z){maxSegmentSize=z;}
	int getMaxBlockSizeInBit(){return maxSegmentSize;}
	void prepare(int);
	Segments& prepare(BitString);

	int getCRCLen(){return gpLen;}
	int getNumSegments(){return segmentNum;}
	int getNumBitsAfter(){return bitNumWithoutFiller;}

	int getKPlus(){return bigSegmentSize;}
	int getKMinus(){return smallSegmentSize;}
	void encode(char filler='0');

	BitString toString(char*, int);
	BitString toString(int);

private:
	void calculate();

	void encodeBlockCRC(char*, int);
};


#endif /* SEGMENT_H_ */
