#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	int n, i;
	unsigned long long int k = 1;
	cin >> n;
	for(i = 2; i <= n; i++) {
		k*= i;
		k%=10000;
	}
	if(k==0) cout << "0000";
	else cout << k;
	return 0;
}