
#include "CppUTest/TestHarness.h"

#include "CRC.h"

TEST_GROUP(TestCrcCheck)
{
	CRC crc;
	String str;
	void setup()
	{
		crc.setGp("11");
	}
};

TEST(TestCrcCheck,INPUT_EMPTY_STRING)
{
	bool result=crc.check("","");
	CHECK_TRUE(result);
}


TEST(TestCrcCheck,INPUT_STRING_1)
{
	bool result=crc.check("1","1");
	CHECK_TRUE(result);
}

TEST(TestCrcCheck,INPUT_STRING_2)
{
	bool result=crc.check("0","1");
	CHECK_FALSE(result);
}

TEST(TestCrcCheck,INPUT_STRING_3)
{
	bool result=crc.check("0","0");
	CHECK_TRUE(result);
}

TEST(TestCrcCheck,INPUT_STRING_4)
{
	bool result=crc.check("1","0");
	CHECK_FALSE(result);
}


TEST(TestCrcCheck,CRCEnable)
{
	String b("1");
	b=b+"0";
	CHECK_FALSE(crc.check(&b));
}
