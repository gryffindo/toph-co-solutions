#include<bits/stdc++.h>
using namespace std;

int main() {
	int cases, number[100];
	double rAverage, something = 0;
	cin >> cases;
	for(int i = 1; i <= cases; i++) {
		cin >> number[i];
		something += number[i];
		rAverage = something / i;
		cout << setprecision(10) << rAverage << endl;
	}
	return 0;
}