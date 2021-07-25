#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, sum, missing;
	cin >> sum;
	cin >> a >> b >> c;
	missing = sum-(a+b+c);
	cout << missing << endl;
	return 0;
}