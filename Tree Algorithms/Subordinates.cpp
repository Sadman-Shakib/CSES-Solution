#include <bits/stdc++.h>
using namespace std;
 
#define ff               first
#define sc               scanf
#define endl             '\n'
#define pf               printf
#define ss               second
#define in               insert
#define clr(arr, x)      memset(arr, x, sizeof arr);
#define not_psble        {cout <<   -1  << endl; return; }
#define YES              {cout << "YES" << endl; return; }
#define NOO              {cout << "NO"  << endl; return; }
#define pp               pop_back
#define pb               push_back
#define mp               make_pair
#define rep(i, l, r)     for(int i = l; i < r; ++i)
#define printarr(arr)    for(int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
#define all(x)           x.begin(), x.end()
#define rall(x)          x.rbegin(), x.rend()
#define printans         cout << ans << endl;
#define int              long long
#define arrin(v, n)      {for(int i = 0; i < n; ++i) cin >> v[i];}
 
 
const int N = 1e6 + 10;
vector <int> g[N];
int ans[N];
 
void dfs(int u) {
        ans[u] = 1;
        for(int i : g[u]) {
                dfs(i);
                ans[u] += ans[i];
        }
}
 
 
void solve() {
 
        int n; cin >> n; 
        for(int i = 0; i < n - 1; i++) {
                int x; cin >> x;
                g[x].pb(i + 2);
        }
 
        dfs(1);
 
        for(int i = 1; i <= n; i++) cout << ans[i] - 1 << " ";
        cout << endl;
}
 
int32_t main() {
 
        // S4DM4N S4K1B 
        ios_base::sync_with_stdio(false); 
        cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif 
        int clock_start = clock(); // clock start
 
        //cin >> t; 
    
        for(int i = 1; i <= t; ++i){
                //cout << "Case " << i << ": ";
                solve();
        }
 
#ifndef ONLINE_JUDGE
        cerr << (double) (clock() - clock_start) / CLOCKS_PER_SEC << endl; // CLOCKS_PER_SEC = 1000
#endif
        return 0;
}
