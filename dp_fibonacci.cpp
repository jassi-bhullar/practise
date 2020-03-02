#include <bits/stdc++.h>
using namespace std;

// int fib(int n)
// {
// 	if(n <= 1)
// 		return 1;

// 	return fib(n-1) + fib(n-2);
// }

int dp[100] = {0};

int fib(int n)
{
	if(n <= 1)
	{
		return n;
	}

	if(dp[n] != 0)
		return dp[n];

	dp[n] = fib(n-1) + fib(n-2);
	return dp[n];
}

int main()
{
	// for (int i = 0; i < 10; ++i)
	// {
	// 	cout << "fib(" <<  i << "): " << fib(i) << endl;
	// }

	cout << fib(9) << endl;

	return 0;
}