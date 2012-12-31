
#include "CppUTest/TestHarness.h"

#include "CRC.h"

TEST_GROUP(TestString)
{
	BitString str;
	GeneratorPolynomials gp;
	void setup()
	{
		gp.set("1011");
	}
};

TEST(TestString, divide)
{
	str="1101001110100000";
	STRCMP_EQUAL("100",str.divide(gp).toString().c_str());
}

TEST(TestString,isDivisible)
{
	str="11010011101100100";
	CHECK_TRUE(str.isDivisible(gp));
}
