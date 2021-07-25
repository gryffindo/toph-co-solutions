#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[5], c[5];

int main() {
   for(int i=1; i<=3; i++) cin >> a[i];
   int q;
   cin >> q;
   while(q--) {
      int x, y;
      scanf("%d %d", &x, &y);
      swap(a[x], a[y]);
      for(int i=1; i<=3; i++) c[i] += a[i];
   }
   for(int i=1; i<=3; i++) printf("%d ", c[i]);
}