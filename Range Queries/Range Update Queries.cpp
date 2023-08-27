#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const int MAX = 1e6;
 
int tree[4*MAX], lazy[4*MAX], a[MAX];
 
void build(int n, int l, int r) {
    if(l == r) {
        tree[n] = a[l]; return;
    }
    int mid = (l + r) / 2;
    int lc = n * 2;
    int rc = lc + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
        
    tree[n] = tree[lc] + tree[rc];
        
}
 
void upd(int n, int i, int j, int l, int r, int v) {
        if(lazy[n]>0) {
                tree[n] += (j - i + 1) * lazy[n];
                int lc = n * 2;
                int rc = lc + 1;
                if(i!=j) {
                        lazy[lc] += lazy[n];
                        lazy[rc] += lazy[n];
                }
                lazy[n] = 0;
        }
        if(i > r or j < l) return; 
        if(i >= l and j <= r) {
                lazy[n] += v;
                tree[n] += (j - i + 1) * lazy[n];
                int lc = n * 2;
                int rc = lc + 1;
                if(i!=j) {
                        lazy[lc] += lazy[n];
                        lazy[rc] += lazy[n];
                }
                lazy[n] = 0;
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
        if(lazy[n]>0) {
                tree[n] += (j - i + 1) * lazy[n];
                int lc = n * 2;
                int rc = lc + 1;
                if(i!=j) {
                        lazy[lc] += lazy[n];
                        lazy[rc] += lazy[n];
                }
                lazy[n] = 0;
        }
        if(i > r or j < l) return 0;
        if(i >= l and j <= r) return tree[n];
        int mid = (i + j) / 2;
        int lc = n * 2;
        int rc = lc + 1;
        return query(lc, i, mid, l, r) + query(rc, mid + 1, j, l, r);
}
 
void solve() {
        
        int n; cin >> n;
        int m; cin >> m;
        for(int i=1; i<=n; i++) cin>>a[i];
        build(1, 1, n);
        
        while(m--) {
                int t; cin >> t;
                if(t == 1) {
                        int l, r, v; cin >> l >> r >> v;
                        upd(1, 1, n, l , r, v);
                } else {
                        int l, r; cin >> l;
                        cout << query(1, 1, n, l, l) << endl;
                }
        }
        
}
 
 
signed main() {
 
        solve();
        
        return 0;
}
