#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
	int array[50], i, n;
	cin >> n;
	array[0] = 1;
	array[1] = 1;
	for(i = 2; i < n; i++) {
		array[i] = array[i-1] + array[i-2];
	}
	cout << array[n-1];
	return 0;
}