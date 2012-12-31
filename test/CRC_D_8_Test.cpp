
#include "CppUTest/TestHarness.h"

#include "CRC.h"

// generator polynomials is gcrc2(D)=D+1
TEST_GROUP(TestCRCD8)
{
	CRC crc;
	BitString b;
	void setup()
	{
		crc.setGp("110011011");
	}
};

TEST(TestCRCD8,INPUT_EMPTY_STRING)
{
	BitString b("");
	CHECK_TRUE(crc.validate(&b));
}

TEST(TestCRCD8,STRING_1)
{
	BitString b("110011011");
	CHECK_TRUE(crc.validate(&b));
}

TEST(TestCRCD8,STRING_2)
{
	BitString b("110011010");
	CHECK_FALSE(crc.validate(&b));
}
