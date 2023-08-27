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
 
const int MAX = 2e5 + 10;
vector <int> g[MAX];
int dis = 0, maxnode = 0;
int tmp[MAX];
 
void dfs(int u, int p) {
        tmp[u] = 1 + tmp[p];
        if(dis < tmp[u]) {
                dis = tmp[u];
                maxnode = u;
        }
        for(auto i: g[u]) {
                if(i != p) {
                        dfs(i, u);
                }
        }
}
 
int x[MAX], y[MAX];
 
void dfs2(int u, int p, int id) {
 
        if(id == 1)     x[u] = 1 + x[p];
        if(id == 2)     y[u] = 1 + y[p];
        
        for(auto i: g[u]) {
                if(i != p) {
                        if(id == 1)     dfs2(i, u, 1);
                        
                        else    dfs2(i, u, 2);
                }
        }
}
 
 
void solve() {
 
        int n; cin >> n;
 
        clr(tmp, 0);
 
        rep(i, 0, n + 10) {
                g[i].clear();
        }
 
        rep(i, 1, n) {
                int u, v, w;
                cin >> u >> v;
                
                g[u].pb(v);
                g[v].pb(u);
                
        }
 
        dfs(1, 0);
 
        int node1 = maxnode;
 
        clr(tmp, 0);
 
        dis = 0;
 
 
 
        dfs(node1, 0);
 
        int node2 = maxnode;
 
        clr(tmp, 0);
 
        dis = 0;
 
 
        dfs2(node1, 0, 1); dfs2(node2, 0, 2);
 
        for(int i = 1; i <= n; i++) cout << max(x[i], y[i]) - 1 << endl;
 
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
                //cout << "Case " << i << ":\n";
                solve();
        }
 
#ifndef ONLINE_JUDGE
        cerr << (double) (clock() - clock_start) / CLOCKS_PER_SEC << endl; // CLOCKS_PER_SEC = 1000
#endif
        return 0;
}
