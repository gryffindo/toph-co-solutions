#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int LOG = 17;
const int N = 100100;
int n, q;
pii sparse[LOG][N];
int p2[N];
int a[N][2];
int par[N][LOG];

pii getMax(int l, int r) {
	int k = p2[r - l];
	return max(sparse[k][l], sparse[k][r - (1 << k)]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;
	for (int i = 0; i < N; i++)
		sparse[0][i] = mp(-1, -1);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][1] += a[i][0];
		a[i][1] = min(a[i][1], N - 1);
		sparse[0][a[i][0]] = max(sparse[0][a[i][0]], mp(a[i][1], i));
	}
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i + (1 << (k + 1)) <= N; i++)
			sparse[k + 1][i] = max(sparse[k][i], sparse[k][i + (1 << k)]);

	for (int i = 0; i < n; i++) {
		par[i][0] = getMax(a[i][0], a[i][1] + 1).second;
	}
	for (int k = 0; k < LOG - 1; k++)
		for (int i = 0; i < n; i++)
			par[i][k + 1] = par[par[i][k]][k];

	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 1;
		int v = getMax(l, l + 1).second;
		if (a[v][1] < r) {
			for (int k = LOG - 1; k >= 0; k--) {
				int u = par[v][k];
				if (a[u][1] < r) {
					v = u;
					ans += 1 << k;
				}
			}
			ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}