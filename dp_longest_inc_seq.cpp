#include <bits/stdc++.h>
using namespace std;

int lis(int *arr, int n)
{
	int lis[n];

	lis[0] = 1;

	int m = 1;

	for(int i=1; i < n; i++)
	{
		lis[i] = 1;

		for(int j=0; j < i; j++)
		{
			if(arr[i] > arr[j] && lis[i] < 1 + lis[j])
				lis[i] = 1 + lis[j];
		}

		if(m < lis[i])
			m = lis[i];
	}

	return m;
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    cout << "Length of lis is " << lis( arr, n ) << endl; 
    return 0; 
}