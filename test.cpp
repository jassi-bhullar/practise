#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A)
{
    int n = A.size();
    if(n == 0)
    	return 0;

    int m = A[0].size();

    int count[n][m];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; ++i)
    {
    	for (int j = 1; j < m; ++j)
    	{
    		if(count[i][j])
    			count[i][j] += count[i][j-1];
    	}
    }

    
}

int main()
{
	vector<vector<int> > A;
	solve(A);
	return 0;
}