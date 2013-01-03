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
	Segments segments;
	CRC crc;
	BitString b;
	int numOfBits;

	void setup()
	{
		segments.setMaxBlockSizeInBit(6144);
		crc.setGp(CRC::GCRC24A);
	}

};

TEST(TestSegment, should_be_1_segment_for_num_of_bit_less_than_max_block_size)
{
	int Z = segments.getMaxBlockSizeInBit();
	numOfBits=Z-1;
	segments.prepare(numOfBits);

	LONGS_EQUAL(0,segments.getCRCLen());
	LONGS_EQUAL(1,segments.getNumSegments());
	LONGS_EQUAL(numOfBits,segments.getNumBitsAfter());
}

TEST(TestSegment, should_be_2_segments_for_num_of_bit_more_than_max_block_size)
{
	int Z = segments.getMaxBlockSizeInBit();
	numOfBits=Z+1;
	segments.prepare(numOfBits);

	int crcLen=24;
	int numSegments=2;
	LONGS_EQUAL(crcLen,segments.getCRCLen());
	LONGS_EQUAL(numSegments,segments.getNumSegments());
	LONGS_EQUAL(numOfBits+crcLen*numSegments,segments.getNumBitsAfter());
}


TEST(TestSegment, should_be_0_for_small_input_bit_sequence)
{
	numOfBits=10;
	segments.prepare(numOfBits);

	LONGS_EQUAL(0, segments.getKMinus());
}

TEST(TestSegment, segment_size_4_large_input_sequence)
{
	numOfBits=6145;
	segments.prepare(numOfBits);

	LONGS_EQUAL(3136, segments.getKPlus());
	LONGS_EQUAL(3072, segments.getKMinus());
}

TEST(TestSegment, fill_0)
{
	BitString a("1101001110100");
	BitString p("100");
	BitString b=a+p;

	segments.prepare(b).encode();

	LONGS_EQUAL(40, segments.segmentLenArray[0]);
	STRCMP_EQUAL("0000000000000000000000001101001110100100",
			segments.toString(0).toString().c_str());
}
