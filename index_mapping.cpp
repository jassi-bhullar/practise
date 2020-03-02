#include <bits/stdc++.h>
using namespace std;

const int M = 100;
const int N = 2;

void insert(int *arr, int n, int hash[M][N])
{
	for (int i = 0; i < n; ++i)
	{
		int x = arr[i];

		if(x < 0)
			hash[abs(x)][1] = 1;
		else
			hash[x][0] = 1;
	}
}

bool search(int x, int hash[M][N])
{
	if(x < 0)
		return hash[abs(x)][1];
	else
		return hash[x][0];
}

int main() 
{ 
    int a[] = { -1, 9, -5, -8, -5, -2 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    
    int hash[M][2];

    for (int i = 0; i < M; ++i)
    {
    	hash[i][0] = 0;
    	hash[i][1] = 0;
    }

    insert(a, n, hash); 

    int X = -8; 
    if (search(X, hash) == true) 
       cout << "Present\n";  
    else
       cout << "Not Present\n"; 
    return 0; 
} 