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


ll MOD = (ll)1e7 + 19;
ll add(ll x, ll y, ll md) {
	x += y;
	if (x >= md) return x - md;
	return x;
}
ll sub(ll x, ll y, ll md) {
	x -= y;
	if (x < 0) return x + md;
	return x;
}
ll mult(ll x, ll y, ll md) {
	return (x * y) % md;
}
ll bin_pow(ll x, ll p, ll md) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1, md), md);
	return bin_pow(mult(x, x, md), p / 2, md);
}
ll rev(ll x, ll md) {
	return bin_pow(x, md - 2, md);
}

bool isPrime(ll x) {
	for (ll y = 2; y * y <= x; y++) {
		if (x % y == 0)
			return false;
	}
	return true;
}

const int N = (int)1e6 + 7;
ll F1[N], F2[N];
ll RF1[N];
ll ANS[N];
int n;
int a[N];
int nxt[N];
int lst[N];
bool used[N];

struct Segm {
	int l, r, val, t;

	Segm() : l(), r(), val(), t() {}
	Segm(int _l, int _r, int _val, int _t) : l(_l), r(_r), val(_val), t(_t) {}

	bool operator < (const Segm &S) const {
		return l < S.l;
	}
};
set<Segm> setik;

void updateAns(int lx, int rx, int ly, int ry, int k) {
	eprintf("updateAns %d %d %d %d %d\n", lx, rx, ly, ry, k);
	lx++;
	rx++;
	ANS[k] = mult(ANS[k], bin_pow(mult(F1[rx], RF1[lx], MOD), sub(F2[ry], F2[ly], MOD - 1), MOD), MOD);
}

void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i <= n; i++)
		lst[i] = n;
	for (int i = n - 1; i >= 0; i--) {
		nxt[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	setik.clear();
	for (int i = 0; i <= n; i++)
		ANS[i] = 1;
	for (int i = 0; i <= n; i++)
		used[i] = 0;
	int X = 0;
	for (int i = 0; i < n; i++) {
		used[a[i]] = 1;
		while(used[X]) X++;
		setik.insert(Segm(i + 1, i + 2, X, 0));
	}
	for (int l = 0; l < n; l++) {
		assert(!setik.empty());
		Segm S = *setik.begin();
		setik.erase(setik.begin());
		updateAns(S.t, l + 1, l + 1, l + 2, S.val);
		S.l++;
		if (S.l < S.r) setik.insert(S);
		if (l == n - 1) break;
		int k = a[l];
		int p = nxt[l];
		auto it = setik.upper_bound(Segm(p + 1, -1, -1, -1));
		assert(it != setik.begin());
		it--;
		if (it->val < k) continue;
		S = *it;
		updateAns(S.t, l + 1, S.l, p + 1, S.val);
		it = setik.erase(it);
		if (S.r > p + 1) {
			setik.insert(Segm(p + 1, S.r, S.val, S.t));
			it = setik.lower_bound(Segm(p + 1, S.r, S.val, S.t));
		}
		int L = S.l;
		while(it != setik.begin()) {
			it--;
			if (it->val < k) break;
			S = *it;
			updateAns(S.t, l + 1, S.l, S.r, S.val);
			it = setik.erase(it);
			L = S.l;
		}
		setik.insert(Segm(L, p + 1, k, l + 1));
	}
	for (int i = 0; i <= n; i++)
		printf("%lld\n", ANS[i]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	assert(isPrime(MOD));
	F1[0] = F2[0] = 0;
	F1[1] = F2[1] = 1;
	for (int i = 2; i < N; i++) {
		F1[i] = add(F1[i - 2], F1[i - 1], MOD);
		assert(F1[i] != 0);
		F2[i] = add(F2[i - 2], F2[i - 1], MOD - 1);
	}
	F1[0] = 1;
	for (int i = 1; i < N; i++) {
		F1[i] = mult(F1[i - 1], F1[i], MOD);
		F2[i] = add(F2[i - 1], F2[i], MOD - 1);
	}
	for (int i = 0; i < N; i++)
		RF1[i] = rev(F1[i], MOD);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}