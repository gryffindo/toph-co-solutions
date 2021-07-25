#include<bits/stdc++.h>
using namespace std;

int main() {
	int a , k, b, i, c, min=-1000;
	cin >> k;
	for(i = 1; i <= k; i++) {
		cin >> a;
		if(a > min) {
			min = a;
		}
	}
	cout << min << endl;

	return 0;
}