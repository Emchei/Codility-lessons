// FrogJmp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

int solution(unsigned int X, unsigned int Y, unsigned D)
{
	int jmp = 0;
	//int temp = 0;

	if (X == 0 && Y == 0 && D == 0)
	{
		return 0;
	}
	else 
	{
		
		double temp = (((double)X - (double)Y) / (double)D);

		jmp = ceil(fabs(temp));
		return jmp;
			
	}
}

int main()
{
	unsigned int X = 5, Y = 105, D = 3;

	solution(X,Y,D);
    return 0;
}

