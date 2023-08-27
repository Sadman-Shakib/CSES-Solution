#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
 
const int MAX = 1e6;
 
int tree[4*MAX], a[MAX];
 
void build(int n, int l, int r) {
    if(l == r) {
        tree[n] = a[l]; return; 
    }
    int mid = (l + r) / 2;
    int lc = n * 2;
    int rc = lc + 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);

    tree[n] = max(tree[lc], tree[rc]);
}
 
int ans = 0;
 
void upd(int n, int i, int j, int s) {
        
        if(tree[n] < s) return;
        
        if(i == j and tree[n] >= s) {
                ans = i;
                tree[n] -= s;
                return;
        }
        
        int mid = (i + j) / 2;
        int lc = n * 2;
        int rc = lc + 1;
        
        if(tree[lc] >= s) {
                upd(lc, i, mid, s);
        }
        
        else {
                upd(rc, mid + 1, j, s);
        }
        
        
        tree[n] = max(tree[lc], tree[rc]);
}
 
 
void solve() {
        
        int n, m; cin >> n >> m;
        for(int i=1; i<=n; i++) cin>>a[i];
        build(1, 1, n);
        for(int i=1; i<=m; i++) {
                int val; cin >> val;
                ans = 0; upd(1, 1, n, val);
                cout << ans << " ";
        }
        
        cout << endl;
       
}
 
 
signed main() {
        
        solve();
        
        return 0;
}
 
