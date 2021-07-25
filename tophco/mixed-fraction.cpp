#include<bits/stdc++.h>
using namespace std;

int main() {
	int numerator, denominator, u, x;
	cin >> numerator >> denominator;
	x = numerator / denominator;
	u = numerator - (denominator * x);
	cout << x << " " << u << " " << denominator << endl;
	return 0;
}