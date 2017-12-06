// PermMissingElem.cpp : Defines the entry point for the console application.
// write your code in C++14

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "vector"

int solution(std::vector <int> &A)
{
	if ((A.size() == 0) || A.capacity() == 0)
	{
		return 1;
	}

	//if (A.size() == 1)
	//{
	///	return A[0];
	//}

	//int *ptr = (int *)malloc(sizeof(int) * n);
	//int ele = 0, ele_1 = 0, div_temp;


	//for (int i = 0; i < n; i++)
	//{
	//	ele = a[i];
	//	ptr[i] = ele;
	//	
	//	for (int u = i + 1; u < n; u++)
	//	{
	//		ele_1 = a[u];
	//	    div_temp = abs(ele - ele_1);

	//		if (div_temp == a[u])
	//		{

	//		}
	//	}
	//	
	//}

	//int temp = ptr[N - 1];

	//return temp;
	int sum = 0;
	int idxSum = 0;
	for (unsigned int i = 0; i < A.size(); i++) {
		idxSum += (i + 1);
		sum += A[i];
	}

	int MissingElem = (idxSum + A.size() + 1) -sum;
	return MissingElem;
}


int main()
{
	std::vector <int> A = {1};
	//int U = sizeof(A) / sizeof(A[0]);
	solution(A);

    return 0;
}

