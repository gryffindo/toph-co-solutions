#include<bits/stdc++.h>
using namespace std;

int main() {
	long long int nCases, number[100000];
	double running_Average, something = 0;
	cin >> nCases; 
	for(int i = 1; i <= nCases; i++) {
		cin >> number[i];
		something += number[i];
		running_Average = something / i; 
		cout << setprecision(10) << running_Average << endl;
	}
	return 0;
}