#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int sz = 0;

  ordered_set<pair<string, int> > a;

  vector<string> d;

  int q; cin >> q;

  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      string s; cin >> s;
      d.pb(s);
      a.insert(mp(s, sz));
      sz++;
    } else if(t == 2) {
      int pos, len;
      cin >> pos >> len; pos--;
      a.erase(mp(d[pos], pos));
      d[pos] = d[pos].substr(0, d[pos].size() - len);
      a.insert(mp(d[pos], pos));
    } else {
      int i, j; cin >> i >> j; i--; j--;
      if(d[i] > d[j]) swap(i, j);
      int p1, p2;
      p1 = a.order_of_key(mp(d[j], 1e9));
      p2 = a.order_of_key(mp(d[i], -1));
      cout << p1 - p2 << '\n';
    }
  }

  return 0;
}