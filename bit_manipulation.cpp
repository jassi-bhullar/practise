#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x)
{
	return (x & (x-1))==0;
}

int main()
{
	int x = 2048;

	cout << isPowerOfTwo(x) << endl;

	return 0;
}