// no of sub-matrices in a matrix whose total
// sum of elements is zero

#include <bits/stdc++.h>
using namespace std;

int solve1D(int *arr, int n)
{
	unordered_map<int, int> countSum; // array sum upto i

	int currSum = 0;
	int res = 0;

	for (int i = 0; i < n; ++i)
	{
		currSum += arr[i];

		if(currSum == 0)
			res++;

		if(countSum.find(currSum) != countSum.end())
			res += countSum[currSum];

		countSum[currSum]++;
	}

	return res;
}

int solve2D(vector< vector<int> > &A)
{
	int n = A.size();
	if(n == 0)
		return 0;

	int m = A[0].size();
	int res = 0;
	int tmp[n];

	for (int i = 0; i < m; ++i)
	{
		memset(tmp, 0, sizeof(tmp));
		for (int j = i; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				tmp[k] += A[k][j];
			}
			res += solve1D(tmp, n);
		}
	}

	return res;
}

int main()
{
	vector< vector<int> > A;
	vector<int> a = {-8, 5, 7};
	vector<int> b = {3, 7, -8};
	vector<int> c = {5, -8, 9};

	A.push_back(a);
	A.push_back(b);
	A.push_back(c);

	cout << solve2D(A) << endl;

	return 0;
}