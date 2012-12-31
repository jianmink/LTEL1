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
 * File Name:   SegmentTest.cpp
 * Description: This file contains definitions for 
 *                      up¡­
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-28                 jianmink                  Initial creation ...                        
 ***********************************************************************/


#include "CppUTest/TestHarness.h"

#include "Segment.h"
#include "CRC.h"

TEST_GROUP(TestSegment)
{
	Segment segment;
	CRC crc;
	BitString b;
	void setup()
	{
		segment.setZ(6144);
		crc.setGp(CRC::GCRC24A);
	}

};

TEST(TestSegment, SegmentNum_1)
{
	int B=10;
	segment.prepare(B);
	LONGS_EQUAL(1,segment.getC());
	LONGS_EQUAL(10,segment.getB_());
	LONGS_EQUAL(0,segment.getL());
}

TEST(TestSegment, SegmentNum_2)
{
	int B=6145;
	segment.prepare(B);
	LONGS_EQUAL(24,segment.getL());
	LONGS_EQUAL(2,segment.getC());
	LONGS_EQUAL(6145+24*2,segment.getB_());
}


TEST(TestSegment, SegmentSize)
{
	int B=10;
	segment.prepare(B);

	LONGS_EQUAL(40, segment.getK1());
}

TEST(TestSegment, SegmentSize_large)
{
	int B=6145;
	segment.prepare(B);

	LONGS_EQUAL(3136, segment.getK1());
}

int ceil(float);
TEST(TestSegment, ceil)
{
	LONGS_EQUAL(2,ceil(1.00408));
	LONGS_EQUAL(1,ceil(1));
}


TEST(TestSegment, fill_0)
{
	BitString b("1101001110100");
	BitString p=crc.encode(&b);

	BitString b_=b+p;

	segment.prepare(b_.toString().length());
	segment.encode(b_,'0');

}

