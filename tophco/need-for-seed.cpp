#include<bits/stdc++.h>
using ll = long long int;
using namespace std;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
using ld = long double;
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val)->(strictly less than val) *s.find_by_order(ind)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.push_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}
#define EVARS(args...) {__evars_begin(__LINE__); __evars(split(#args, ',').begin(), args);}
inline void __evars_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __evars_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __evars_out_var(T* val) { cerr << arrStr(val, 10); }
template<typename T> inline void __evars_out_var(T val) { cerr << val; }
inline void __evars(vector<string>::iterator it) { cerr << endl; }
template<typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __evars_out_var(a);
    cerr << "; ";
    __evars(++it, args...);
}
const int N = 1e6 + 5;
int main()
{
	sync;
	clock_t clk = clock();
    int t;
    cin >> t;
    while(t--){
        int n, m, Q;
        cin >> n >> m >> Q;
        vector<int> diff(n);
        input(diff, n);
        vector<pair<int, int> > v[n];
        for(int i = 0; i < m; i++){
            int x, y, w;
            cin >> x >> y >> w;
            if(diff[x] < diff[y])
                swap(x, y);
            v[x].push_back({w, y});
            //cout << x << " " << y << endl;
        }
        while(Q--){
            int X, Y;
            cin >> X >> Y;
            vector<int> in(n);
            for(int i = 0; i < n; i++){
                for(auto x: v[i]){
                    in[x.S]++;
                }
            }
            vector<ll> dp(n, 1e18);
            queue<int> q;
            for(int i = 0; i < n; i++){
                if(!in[i]){
                    q.push(i);
                }
            }
            dp[X] = 0;
            while(!q.empty()){
                int top = q.front();
                q.pop();
                for(auto chd: v[top]){
                    dp[chd.S] = min(dp[top] + chd.F, dp[chd.S]);
                    in[chd.S]--;
                    if(!in[chd.S])
                        q.push(chd.S);
                }
            }
            //EVARS(dp);
            cout << (dp[Y] == 1e18 ? -1 : dp[Y]) << "\n";
        }
    }


 	//cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';	
}