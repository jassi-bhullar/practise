#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &A)
{
    int n = A.size();
    int cnt = 0;
    
    if(n <= 2)
        return n;
        
    int lap[n] = {0};
    int m = 2;
    int M = 2;
    
    for(int i=n-1; i >= 0; i--)
    {
    	if(lap[i] != 0)
    		break;

        for(int j = i+1; j < n; j++)
        {
            int ptr = A[j];
            int diff = A[j] - A[i];
            int curr = 2;
            
            for(int k = j+1; k < n; k++)
            {
            	cnt++;
                if(A[k] == ptr + diff)
                {
                    curr++;
                    ptr = A[k];
                }
            }
            
            if(m < curr)
                m = curr;
        }

        lap[i] = m;

        if(M < m)
        	M = m;
    }

    return M;
}

void display(const vector<int>& A)
{
	for(auto x: A)
	{
		cout << x << " ";
	}
	cout << endl;
}

int sum(int *arr, int n)
{
    unordered_map<int, int> prevSum;
    
    int currSum = 0;
    int res = 0;
    
    for(int i=0; i < n; i++)
    {
        currSum += arr[i];
        
        if(currSum == 0)
            res++;
        
        if(prevSum.find(currSum) != prevSum.end())
            res += prevSum[currSum];
            
        prevSum[currSum]++;
    }
}

int Solution::solve(vector<vector<int> > &A)
{
    int n = A.size();
    if(n == 0)
        return 0;
    
    int m = A[0].size();
    int res = 0;
    
    for(int i=0; i < m; i++)
    {
        int tmp[n] = {0};

        for(int j=i; j < m; j++)
        {
            for(int k=0; k < n; k++)
                tmp[k] += A[k][j];

            res += sum(tmp, n);
        }
    }
    
    return res;
}


int main()
{
	int arr[] = {3, 2, 12, 4, 5, 6, 18, 8, 11, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	const vector<int> A(arr, arr + n);

	cout << solve(A) << endl;

	return 0;
}