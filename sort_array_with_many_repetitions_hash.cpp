// [n = no of elements, m = no of distinct elements]
// Time Complexity: n + mLog(m)

#include <bits/stdc++.h>
using namespace std;

void sort(int *arr, int n)
{
	unordered_map<int, int> count;

	for (int i = 0; i < n; ++i)
	{
		count[arr[i]]++;
	}

	map<int, int> count_sorted;

	for(auto x: count)
	{
		count_sorted[x.first] = x.second;
	}

	int i = 0;
	for(auto x: count_sorted)
	{
		while(x.second--)
		{
			arr[i++] = x.first;
		}
	}
}

void printArr(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Input array is\n"; 
	printArr(arr, n); 

	sort(arr, n); 

	cout << "Sorted array is\n"; 
	printArr(arr, n); 

	return 0;
}