#include <bits/stdc++.h>
using namespace std;

void foo()
{
	int n = 4;

	for(int i=0; i < 5; i++)
	{
		int tmp[n] = {0};

		for(int i=0; i < n; i++)
			cout << tmp[i] << " ";
		cout << endl;
	}
}

int main()
{
	foo();

	return 0;
}