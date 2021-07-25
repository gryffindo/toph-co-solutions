#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int n, q;
vector <tuple<int,int,int>> beg[sz], fin[sz];
ll one[sz], two[sz];

void add1(int x, ll v) {
   while(x <= q) {
      one[x] += v;
      x += x & -x;
   }
}

ll quer1(int x) {
   ll res = 0;
   while(x) {
      res += one[x];
      x -= x & -x;
   }
   return res;
}

void add2(int x, ll v) {
   while(x) {
      two[x] += v;
      x -= x & -x;
   }
}

ll quer2(int x) {
   ll res = 0;
   while(x <= q) {
      res += two[x];
      x += x & -x;
   }
   return res;
}

void solve() {
   scanf("%d %d", &n, &q);
   for(int i=1; i<=n; i++) one[i] = two[i] = 0, beg[i].clear(), fin[i].clear();
   for(int i=1; i<=q; i++) {
      int t, l, r, k;
      scanf("%d %d %d %d", &t, &l, &r, &k);
      beg[l].emplace_back(t, i, k);
      fin[r].emplace_back(t, i, k);
   }
   ll ans = 0;
   for(int e=1; e<=n; e++) {
      for(auto &[t, i, k] : beg[e]) {
         if(t == 1) {
            ans += k * quer2(i);
            add1(i, k);
         }
         else {
            ans += k * quer1(i);
            add2(i, k);
         }
      }
      printf("%lld ", ans);
      for(auto &[t, i, k] : fin[e]) {
         if(t == 1) {
            ans -= k * quer2(i);
            add1(i, -k);
         }
         else {
            ans -= k * quer1(i);
            add2(i, -k);
         }
      }
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}