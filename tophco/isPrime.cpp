#include <bits/stdc++.h>
using namespace std;

int isPrime(int n);
int main()
{
	int n;
	cin >> n;
	if (isPrime(n) == 1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}

int isPrime(int n)
{
	int i;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}