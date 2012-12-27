
#include "CppUTest/TestHarness.h"

#include "CRC.h"

// generator polynomials is gcrc2(D)=D+1
TEST_GROUP(TestCrcCheck)
{
	CRC crc;
	String b;
	void setup()
	{
		crc.setGp("11");
	}
};

TEST(TestCrcCheck,INPUT_EMPTY_STRING)
{
	String b("");
	CHECK_TRUE(crc.check(&b));
}


TEST(TestCrcCheck,INPUT_STRING_1)
{
	String b("1");
	b=b+"1";
	CHECK_TRUE(crc.check(&b));
}

TEST(TestCrcCheck,INPUT_STRING_2)
{
	String b("0");
	b=b+"1";
	CHECK_FALSE(crc.check(&b));
}

TEST(TestCrcCheck,INPUT_STRING_3)
{
	String b("0");
	b=b+"0";
	CHECK_TRUE(crc.check(&b));
}


TEST(TestCrcCheck,CRCEnable)
{
	String b("1");
	b=b+"0";
	CHECK_FALSE(crc.check(&b));
}
