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

#include "Text.h"
String::String()
{
	s="";
}

string String::strip(string str)
{
	int i=0;
	for(; i<str.length()&&str[i]=='0'; i++);

	if(i==str.length())
		return "";
	else
		return str.substr(i);
}

bool String::isDivideRemainderZero(GeneratorPolynomials gp)
{
	string& b=s;
	string bb=strip(b);
	if(bb=="")
		return true;

	string gpStr=gp.getGpString();

	if(bb.length()<gpStr.length())
		return false;

	String bbb=Xor(bb.substr(0,gpStr.length()),gpStr)
		+bb.substr(gpStr.length());

	return bbb.isDivideRemainderZero(gp);
}


string String::Xor(string a, string b)
{
	string r=a;
	if(a.length()!=b.length())
		return "length failure";

	for(int i=0; i<a.length(); i++)
	{
		if(a[i]==b[i])
			r[i]='0';
		else
			r[i]='1';
	}
	return r;
}


bool String::operator==(String str)
{
	return s==str.s;
}

String String::operator+(String str)
{
	return String(s+str.s);
}
