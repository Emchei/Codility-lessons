// TapeEquilibrium.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include <vector>

int solution (std::vector<int> &A)
{
	//if (N == 0)
	//{(sizeof(A) / sizeof(A[0]));
		//return 0;
	//}
	//if (N == 1)
	//{
	//	return A[0];
	//}
	int N = A.size();
	int *ptr_sum = (int *)malloc(sizeof(int) * N);
	int sum_ele = 0;

	for (int i = 0; i < N; i++)
	{
		sum_ele += A[i];
		ptr_sum[i] = sum_ele;

	}

	int sumAll = ptr_sum[N - 1];
	int temp = 0;

	for (int i = 0; i < N - 1; i++)
	{
		//temp = A[i];
		temp = abs(ptr_sum[N - 1] - 2 * ptr_sum[i]);

		sumAll = (sumAll == ptr_sum[N - 1] && i == 0) ? temp : sumAll;


		if (sumAll > temp || sumAll < 0)
		{
			sumAll = temp;
		}

	}

	return sumAll;
}

int main()
{
	//int U[] = { 5,1,8,4,8,5,1,4,9,4,10 };
	std::vector <int>U = {3,1,2,4,3};
	//int L = (sizeof(U)/sizeof(U[0]));
	solution(U);

    return 0;
}

