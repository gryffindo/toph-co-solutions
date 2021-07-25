#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		double gons, angle;
		cin >> gons;
		angle = 180 * (gons-2); // simple formula 😎
		angle = angle / gons;
		cout << setprecision(6) << angle << endl;;
	}
	return 0;
}