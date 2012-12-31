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
 * File Name:   Generatorpolynomials.h
 * Description: This file contains definitions for 
 *                      up¡­
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-31                 jianmink                  Initial creation ...                        
 ***********************************************************************/


#ifndef GENERATORPOLYNOMIALS_H_
#define GENERATORPOLYNOMIALS_H_

using namespace std;
#include <string>

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


#endif /* GENERATORPOLYNOMIALS_H_ */
