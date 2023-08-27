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
 
const int MAX = 1e5 + 10;
int indeg[MAX];
vector <int> g[MAX];
int vis[MAX];
 
void solve() {
 
        int n, m; cin >> n >> m;
 
        rep(i, 0, m) {
                int l, r; cin >> l >> r;
                indeg[r]++; g[l].pb(r);
        }
 
        vector <int> z;
 
        for(int i = 1; i <= n; i++) if(indeg[i] == 0) { vis[i]++; z.pb(i); }
 
        vector <int> ans;
 
        while(ans.size() < n) {
                if(z.size() == 0) {
                        cout << "IMPOSSIBLE" << endl; return;
                }
                int cur = z.back(); z.pp();
                ans.pb(cur);
                for(int i: g[cur]) {
                        if(vis[i] == 0) {
                                indeg[i]--;
                                if(indeg[i] == 0) {
                                        vis[i]++;
                                        z.pb(i);
                                }
                        }
                }
        }
 
        for(int i: ans) cout << i << " ";
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
