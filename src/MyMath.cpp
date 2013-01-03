/*
 * MyMath.cpp
 *
 *  Created on: 2013-1-3
 *      Author: jianmink
 */

int ceil(float v)
{
	int n=(int)v;
	if(v-n!=0)
		return n+1;

	return n;
}

int floar(float v)
{
	return (int)v;
}



