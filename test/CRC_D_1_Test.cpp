
#include "CppUTest/TestHarness.h"

#include "CRC.h"

// generator polynomials is gcrc2(D)=D+1
TEST_GROUP(TestCrcCheck)
{
	CRC crc;
	BitString b;
	void setup()
	{
		crc.setGp("11");
	}
};

TEST(TestCrcCheck,INPUT_EMPTY_STRING)
{
	BitString b("");
	CHECK_TRUE(crc.check(&b));
}


TEST(TestCrcCheck,INPUT_STRING_1)
{
	BitString b("1");
	b=b+"1";
	CHECK_TRUE(crc.check(&b));
}

TEST(TestCrcCheck,INPUT_STRING_2)
{
	BitString b("0");
	b=b+"1";
	CHECK_FALSE(crc.check(&b));
}

TEST(TestCrcCheck,INPUT_STRING_3)
{
	BitString b("0");
	b=b+"0";
	CHECK_TRUE(crc.check(&b));
}


TEST(TestCrcCheck,CRCEnable)
{
	BitString b("1");
	b=b+"0";
	CHECK_FALSE(crc.check(&b));
}
