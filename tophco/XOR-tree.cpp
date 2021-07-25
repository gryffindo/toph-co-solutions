#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

using namespace std;

const int LG = 30;
const int N = 100010;
const int M = 4000010;

vector <int> g[N];
vector <pair <int, int>> adj[N];
int tests, n, q, k, ptr, par[N], arr[N];
vector <tuple <int, int, int>> queries[N];
int sz[N], h[N], in[N], nxt[N], d[N], to[M][2], last[M][2], ans[N];

void insert (int x, int idx) {
  int u = 1;
  for (int i = LG - 1; i >= 0; --i) {
    int bit = x >> i & 1;
    int &v = to[u][bit];
    if (!v) v = ++ptr;
    last[u][bit] = idx; u = v;
  }
}

void query (int x, int r, int idx) {
  int ret = 0, u = 1;
  for (int i = LG - 1; i >= 0; --i) {
    int bit = x >> i & 1;
    if (to[u][bit ^ 1] and last[u][bit ^ 1] <= r) {
      u = to[u][bit ^ 1];
      ret |= 1 << i;
    } else {
      u = to[u][bit];
    }
  }
  ans[idx] = max(ans[idx], ret);
}

void go (int u = 1, int par = -1, int cur = 0) {
  d[u] = cur;
  for (auto [v, w] : adj[u]) if (v ^ par) go(v, u, cur ^ w);
}

void dfs (int u = 1, int far = 0) {
  sz[u] = 1, h[u] = far;
  for (int v : g[u]) g[v].erase(find(g[v].begin(), g[v].end(), u));
  for (int &v : g[u]) {
    par[v] = u; dfs(v, far + 1); sz[u] += sz[v];
    if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
  }
}

void hld (int u = 1) {
  in[u] = ++ptr, arr[ptr] = d[u];
  for (int v : g[u]) {
    nxt[v] = (v == g[u][0] ? nxt[u] : v); hld(v);
  }
}

void climb (int u, int v, int x, int idx) {
  while (nxt[u] ^ nxt[v]) {
    if (h[nxt[u]] > h[nxt[v]]) swap(u, v);
    queries[in[nxt[v]]].emplace_back(in[v], x, idx);
    v = par[nxt[v]];
  }
  if (h[u] > h[v]) swap(u, v);
  queries[in[u]].emplace_back(in[v], x, idx);
}

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> tests;
  while (tests--) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
      adj[i].clear();
    }
    for (int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].push_back(v);
      g[v].push_back(u);
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }
    for (int i = 0; i <= ptr; ++i) {
      to[i][0] = to[i][1] = last[i][0] = last[i][1] = 0;
    }
    ptr = 0; go(); dfs(); nxt[1] = 1; hld();
    for (int i = 1; i <= n; ++i) queries[i].clear();
    for (int i = 1; i <= q; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      climb(u, v, d[u], i); ans[i] = 0;
    }
    ptr = 1;
    for (int i = n; i >= 1; --i) {
      insert(arr[i], i);
      for (auto [r, x, idx] : queries[i]) query(x, r, idx);
    }
    for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
  }
  return 0;
}