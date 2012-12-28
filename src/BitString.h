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


#ifndef TEXT_H_
#define TEXT_H_

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

class CRCEnable{
public:
	virtual bool isDivideRemainderZero(GeneratorPolynomials)=0;
};



class BitString:public CRCEnable{
string s;
public:
	BitString(){s="";}
	BitString(string str){s=str;}
	BitString(const char* c){s=string(c);}
	BitString& operator=(string str){s=str; return *this;}
	bool operator ==(BitString str){return s==str.s;}
	BitString operator+(BitString str){return BitString(s+str.s);}

	string toString(){return s;}

	void leftShift(int);

//CRCEnable
	bool isDivideRemainderZero(GeneratorPolynomials);
	string strip(string);
	BitString divide(GeneratorPolynomials);

private:
	string Xor(string, string);
};




#endif /* TEXT_H_ */
