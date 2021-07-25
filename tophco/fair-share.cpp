#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

int a[sz];
ll cum[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), cum[i] = a[i] + cum[i-1];
   ll lo = *max_element(a, a+n+1), hi = cum[n];
   int c = n;
   for(int i=0; i<k and c>1; i++) c -= c / 2;
   if(c == 1) {
      printf("%lld\n", lo);
      return;
   }
   int d = 1 << k;
   while(lo < hi) {
      ll md = lo + hi >> 1;
      int k = 0;
      for(int i=1; i<=n; k++) {
         i = upper_bound(cum+i, cum+n+1, cum[i-1] + md) - cum;
      }
      if(k <= d) hi = md;
      else lo = md + 1;
   }
   printf("%lld\n", lo);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}