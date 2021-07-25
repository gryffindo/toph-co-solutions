#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; } template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << "  " << H; dbg_out(T...); }

#ifdef SMIE
#define debug(args...) cerr << "(" << #args << "):", dbg_out(args)
#else
#define debug(args...)
#endif

const int mxn = 1e6 + 6;

int mark[mxn];

void gen() {
    for (long long i = 2; i < mxn; i++) {
        if (mark[i] == 0) {
            mark[i] = i;
            for (long long j = i * i; j < mxn; j += i) {
                mark[j] = i;
            }
        }
    }
}

void solve() {
    int l, r, one_size_group_count, big_group_size = 0;

    cin >> l >> r;

    one_size_group_count = r - l + 1;
    if (l == 1) {
        l++;
    }

    for (int i = l; i <= r; i++) {
        if (l <= i - mark[i] or i + mark[i] <= r) {
            big_group_size++;
            one_size_group_count--;
        }
    }

    cout << one_size_group_count + bool(big_group_size) << '\n';
    while (one_size_group_count--) {
        cout << "1\n";
    }
    if (big_group_size > 0) {
        cout << big_group_size << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);   //DON'T mix C and C++ I/O
    cin.tie(NULL);                      //DON'T use for interactive problem

    gen();

    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}