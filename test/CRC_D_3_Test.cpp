
#include "CppUTest/TestHarness.h"

#include "CRC.h"

// generator polynomials is gcrc2(D)=D+1
TEST_GROUP(TestCRCD3)
{
	CRC crc;
	BitString b;
	void setup()
	{
		crc.setGp("1011");
	}
};


TEST(TestCRCD3,STRING_11010011101100)
{
	BitString b("11010011101100100");
	CHECK_TRUE(crc.check(&b));
}

TEST(TestCRCD3,Encode)
{
	BitString b("1101001110100");
	STRCMP_EQUAL("100",crc.encode(&b).toString().c_str());
}
