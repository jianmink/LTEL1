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
 * File Name:   CRC.cpp
 * Description: This file contains definitions for 
 *                      up¡­
 * -------------------------------------------------------------------------------------------------------
 * Change History :                                                                                                 
 * Date                   Author                  Description (FR/CR)                              
 * -------------      -----------------         ----------------------------------------------------------------
 * 2012-12-26                 jianmink                  Initial creation ...                        
 ***********************************************************************/

#include "CRC.h"


const string CRC::GCRC24A="1100001100100110011111011";
const string CRC::GCRC24B="1100000000000000001100011";
const string CRC::GCRC16="10001000000100001";
const string CRC::GCRC8="110011011";

bool CRC::validate(BitString* b)
{
	return b->isDivisible(gp);
}

void CRC::setGp(string aGp)
{
	gp.set(aGp);
}


BitString CRC::encode(BitString* a)
{
	*a<<gp.getL();
	return a->divide(gp);
}
