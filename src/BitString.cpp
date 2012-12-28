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
 * File Name:   String.cpp
 * Description: This file contains definitions for 
 *                      up¡­
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-27                 jianmink                  Initial creation ...                        
 ***********************************************************************/

#include "BitString.h"

string BitString::strip(string str)
{
	int i = 0;
	for (; i < str.length() && str[i] == '0'; i++);

	if (i == str.length())
		return "";
	else
		return str.substr(i);
}

bool BitString::isDivideRemainderZero(GeneratorPolynomials aGp)
{
	string b = strip(s);
	if (b == "")
		return true;

	string gp = aGp.getGp();

	if (b.length() < gp.length())
		return false;

	BitString bbb = Xor(b.substr(0, gp.length()), gp) + b.substr(gp.length());

	return bbb.isDivideRemainderZero(aGp);
}

string BitString::Xor(string a, string b)
{
	string r = a;
	if (a.length() != b.length())
		return "length failure";

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[i])
			r[i] = '0';
		else
			r[i] = '1';
	}
	return r;
}

BitString BitString::divide(GeneratorPolynomials aGp)
{
	string a = strip(s);
	string gp =aGp.getGp();

	if(a.length()<gp.length())
		return a;

	BitString remainder = Xor(a.substr(0,gp.length()),gp)
		+ a.substr(gp.length());

	return remainder.divide(aGp);
}

void BitString::leftShift(int p)
{
	for(int i=0; i<p; i++)
		s+="0";
}
