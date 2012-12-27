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


class CRCEnable{
public:
	virtual bool isDivideRemainderZero(string)=0;
};

class String:public CRCEnable{
string s;
public:
	String();
	String(string str){s=str;}
	String(const char* c){s=string(c);}
	String& operator=(string str){s=str; return *this;}
	bool operator ==(String str);
	String operator+(String str);


//CRCEnable
	bool isDivideRemainderZero(string);
	string strip(string);
private:
	string Xor(string, string);
};


#endif /* TEXT_H_ */
