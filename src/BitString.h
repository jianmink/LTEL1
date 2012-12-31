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
 * File Name:   Text.h
 * Description: This file contains definitions for 
 *                      up¡­
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-27                 jianmink                  Initial creation ...                        
 ***********************************************************************/


#ifndef BITSTRING_H_
#define BITSTRING_H_

#include <iostream>
using namespace std;

class GeneratorPolynomials{
int L;
string gp;
public:
	void set(string aGp)
	{
		gp = aGp;
		L = aGp.length() - 1;
	}
	string getGp(){return gp;}
	int getL(){return L;}
};

class BitString;
class BitStringCRCHelper
{
public:
	BitString divide(BitString, GeneratorPolynomials);
	string Xor(string, string);
	bool isDivisible(BitString, GeneratorPolynomials);

};

class BitString
{
friend class BitStringCRCHelper;
string s;
BitStringCRCHelper helper;
public:
	BitString(){s="";}
	BitString(string str){s=str;}
	BitString(const char* c){s=string(c);}
	BitString& operator=(string str){s=str; return *this;}
	BitString& operator=(const char* c){s=string(c); return *this;}
	bool operator ==(BitString str){return s==str.s;}
	BitString operator+(BitString str){return BitString(s+str.s);}
	char& operator[](int index){return s[index];}
	string toString(){return s;}
	void operator<<(int p){for(int i=0; i<p; i++)s+="0";}

//CRCEnable
	bool isDivisible(GeneratorPolynomials gp)
	{return helper.isDivisible(s,gp);	}
	BitString divide(GeneratorPolynomials gp)
	{return helper.divide(s,gp);}

private:
	string strip();
};


#endif /* TEXT_H_ */
