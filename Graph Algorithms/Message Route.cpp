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
 
vector <int> g[100001];
int mark[100001];
int dis[100001];
 
map <int, int> dir;
 
void bfs(int n) {
        mark[n] = 1;
        queue <int> q;
        q.push(n);
        while(q.size()) {
                int val = q.front();
                for(int i : g[val]) {
                        if(mark[i] == 0) {
                                mark[i] = 1; q.push(i);
                                dis[i] = dis[val] + 1;
                                dir[i] = val;
                        }
                }
                q.pop();
        }
}
 
void solve() {
 
        
        int n, m; cin >> n >> m;
        rep(i, 0, m) {
                int a, b; cin >> a >> b;
                g[a].pb(b); g[b].pb(a);
        }
 
        bfs(1);
        if(mark[n] == 0) {
                cout << "IMPOSSIBLE" << endl; return;
        }
        cout << dis[n] + 1 << endl;
        
 
        vector <int> ans;
        int s = n; 
        while(s != 1) {
                //cout << s << endl;
                ans.pb(s);
                s = dir[s];
        }
        ans.pb(1);
 
        reverse(all(ans));
        
        for(auto i: ans) cout << i << " ";
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
