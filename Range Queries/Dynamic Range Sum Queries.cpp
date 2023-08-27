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
 
 
const int mx = 1e6;
int tree[mx], a[mx];
int n, m;
 
void build(int node, int l, int r) {
        if(l == r) {
                tree[node] = a[l]; return;
        }
        int mid = (l + r) / 2, lc = node * 2, rc = lc + 1;
        build(lc, l, mid); build(rc, mid + 1, r);
        tree[node] = tree[lc] + tree[rc];
}
 
void upd(int n, int i, int j, int l, int r, int v) {
        
        if(i > r or j < l) return; 
        if(i >= l and j <= r) {
                tree[n] = v; a[i] = v;
                return;
        }
        int mid = (i + j) / 2;
        int lc = n * 2;
        int rc = lc + 1;
        upd(lc, i, mid, l, r, v);
        upd(rc, mid + 1, j, l, r, v);
        
        tree[n] = tree[lc] + tree[rc];
        
}
 
 
int query(int n, int i, int j, int l, int r) {
        
        if(i > r or j < l) return 0;
        if(i >= l and j <= r) return tree[n];
        int mid = (i + j) / 2;
        int lc = n * 2;
        int rc = lc + 1;
        return query(lc, i, mid, l, r) + query(rc, mid + 1, j, l, r);
}
 
 
 
void solve() {
 
        cin >> n >> m;
        rep(i, 1, n + 1) cin >> a[i];

        build(1, 1, n);
 
 
        while(m--) {
                int x; cin >> x;
                if(x == 1) {
                        int pos, val; cin >> pos >> val;
                        upd(1, 1, n, pos, pos, val);
                } else {
                        int l, r; cin >> l >> r;
                        cout << query(1, 1, n, l, r) << endl;
                }
        }
 
 
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
