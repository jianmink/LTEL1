
#include "CppUTest/TestHarness.h"

#include "CRC.h"

TEST_GROUP(TestString)
{
	BitString str;
};


TEST(TestString,strip_00)
{
	STRCMP_EQUAL("",str.strip("00").c_str());
}

TEST(TestString,strip_11)
{
	STRCMP_EQUAL("11",str.strip("11").c_str());
}

TEST(TestString,strip_01)
{
	STRCMP_EQUAL("1",str.strip("01").c_str());
}

TEST(TestString,strip_10)
{
	STRCMP_EQUAL("10",str.strip("10").c_str());
}
