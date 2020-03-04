#include <bits/stdc++.h>
using namespace std;

// M is the range of numbers
void countSort(int *arr, int n, int M)
{
	int out[n];
	int count[M+1];
	memset(count, 0, sizeof(count));

	// for negative elements store min
	// element at index 0, and all will
	// be offsetted
	int min = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		if(min > arr[i])
			min = arr[i];
	}

	// count array
	for (int i = 0; i < n; ++i)
	{
		count[arr[i] - min]++;
	}

	// count array to cummulative sum array
	for (int i = 1; i < M+1; ++i)
	{
		count[i] += count[i-1];
	}

	for (int i = 0; i < n; ++i)
	{
		out[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < n; ++i)
	{
		arr[i] = out[i];
	}
}

int main()
{
	int arr[] = {-5, -10, 0, -3, 8, 5, -1, 10};
	int n = sizeof(arr) / sizeof(arr[0]);

	int min = *min_element(arr, arr + n);
	int max = *max_element(arr, arr + n);
	int range = max - min;

	countSort(arr, n, range);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}