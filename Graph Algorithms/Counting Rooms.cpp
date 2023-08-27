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
 
char grid[1005][1005];
map <pair<int, int>, int> vis;
 
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // directional array
// directional array are used for visiting neighobor cell of grid
 
void dfs(int i, int j) {
        vis[mp(i, j)]++;
        grid[i][j] = 'X';
        rep(x, 0, 4) {
                int newX = i + dx[x];
                int newY = j + dy[x];
                if(vis[mp(newX, newY)] == 0 and grid[newX][newY] == '.') dfs(newX, newY);
        }
 
}
 
void solve() {
 
        int n, m; cin >> n >> m;
        rep(i, 0, n) {
                rep(j, 0, m) {
                        cin >> grid[i][j];
                }
        }
        int ans = 0;
        rep(i, 0, n) {
                rep(j, 0, m) {
                        if(vis[mp(i, j)] == 0 and grid[i][j] == '.') {
                                ans = ans + 1;
                                dfs(i, j);
                        }
                }
        }
 
        cout << ans << endl;
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
 
        ///cin >> t; 
    
        for(int i = 1; i <= t; ++i){
                //cout << "Case " << i << ": ";
                solve();
        }
 
#ifndef ONLINE_JUDGE
        cerr << (double) (clock() - clock_start) / CLOCKS_PER_SEC << endl; // CLOCKS_PER_SEC = 1000
#endif
        return 0;
}
