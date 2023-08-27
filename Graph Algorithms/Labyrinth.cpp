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
 
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string direction [4] = {"U", "L", "D", "R"};
 
char grid[10000][10000];
int mark[1001][1001];
 
map <pair<int, int>, pair<int, int> > path;

 
bool isvalid(int x, int y, int n, int m) {
        if(x >= 0 and y >= 0 and x < n and y < m) return true;
        return false;
}
 
void bfs(pair <int, int> pos, int n, int m) {
        mark[pos.ff][pos.ss] = 1;
        queue <pair<int, int> > q;
        q.push(pos); 
        while(q.size()) {
                
                for(int i = 0; i < 4; i++) {
                        int x = q.front().ff + dx[i];
                        int y = q.front().ss + dy[i];
                        if(mark[x][y] == 0 and grid[x][y]!='#' and isvalid(x, y, n, m)) {
                                mark[x][y]++; 
                                q.push({x, y}); 
                                path[{x, y}] = {q.front().ff, q.front().ss};
                        }
                }
                q.pop();
        }
}
 
string build(int a, int b, int x, int y) {
        if(a == x and b + 1 == y) return "L";
        if(a == x and b - 1 == y) return "R";
        if(a + 1 == x and b == y) return "U";
        if(a - 1 == x and b == y) return "D";
}
 
void solve() {
 
        int n, m; cin >> n >> m;
        pair <int, int> pos, start;
 
        rep(i, 0, n) {
                rep(j, 0, m) {
                        cin >> grid[i][j];
                        if(grid[i][j] == 'A') {
                                start = {i, j};
                        }
                        if(grid[i][j] == 'B') {
                                pos = {i, j};
                        }
                }
        }
 
        bfs(start, n, m);
 
        if(mark[pos.ff][pos.ss] == 0) NOO
 
        int dis = 0;
        string ans = "";
 
        while(pos != start) {
                ans += build(pos.ff, pos.ss, path[pos].ff, path[pos].ss);
                pos = path[pos]; ++dis;
 
        }
        reverse(all(ans));
        cout << "YES" << endl;
        cout << dis << endl;
        cout << ans << endl;
 
 
}
 
signed main() {
 
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif 
      
        solve();
 
        return 0;
}
