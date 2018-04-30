// MaxCounters.cpp : Defines the entry point for the console application.
/*
You are given N counters, initially set to 0, and you have two possible operations on them:

	1)	increase(X) − counter X is increased by 1,
	2)	max counter − all counters are set to the maximum value of any counter.
A non-empty zero-indexed array A of M integers is given. This array represents consecutive operations:

	1)	if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
	2)	if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
the values of the counters after each consecutive operation will be:

(0, 0, 1, 0, 0)
(0, 0, 1, 1, 0)
(0, 0, 1, 2, 0)
(2, 2, 2, 2, 2)
(3, 2, 2, 2, 2)
(3, 2, 2, 3, 2)
(3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Assume that the following declarations are given:

struct Results {
	int * C;
	int L;
};

Write a function:

	struct Results solution(int N, int A[], int M);

that, given an integer N and a non-empty zero-indexed array A consisting of M integers, returns a sequence of integers representing the values of the counters.

The sequence should be returned as:

a structure Results (in C), or
a vector of integers (in C++), or

For example, given:

A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Assume that:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
Complexity:

expected worst-case time complexity is O(N+M);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
*/
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct Results {
	int * C;
	int L;
};


struct Results solution(int N, int A[], int M)
{
	struct Results result;
	result.C = (int*)calloc(N, sizeof(N));
	result.L = N;
	int max_counter = 0;
	int max_temp = 0;
	for (unsigned int i = 0; i < M; ++i)
	{
		if (A[i] > 0 && A[i] <= N)
		{
			/*if (result.C[A[i] - 1] < max_counter)
			{
				result.C[A[i] - 1] = max_counter + 1;
			}
		    else {
				result.C[A[i] - 1] += 1;
			}*/// Alternative form
			result.C[A[i] - 1] = (result.C[A[i] - 1] < max_counter) ? max_counter + 1 : result.C[A[i] - 1] + 1;

			if (max_temp < result.C[A[i] - 1])
			{
				max_temp = result.C[A[i] - 1];
			}
				
		}
		else if (A[i] == result.L + 1)
		{
			max_counter = max_temp;
		}
	}

	for (unsigned int i = 0; i < result.L; ++i)
	{
		if (result.C[i] < max_counter)
		{
			result.C[i] = max_counter;
		}
	}
	return result;
}
int main()
{
	int A[] = { 3, 4, 4, 6, 1, 4, 4 };
	int size_n = sizeof(A) / sizeof(int);
	struct Results ptr = solution(5, A, size_n);
	//val = &val1;
    //ptr = (struct Result*) calloc(5, sizeof(struct Results));
	//(&ptr) = ;
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *(&ptr.C[i]));
	}
	
	getchar();
    return 0;
}

