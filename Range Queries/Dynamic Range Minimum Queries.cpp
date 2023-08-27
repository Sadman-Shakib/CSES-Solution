#include <bits/stdc++.h>
using namespace std;
#define int long long 
int tree[10000000], a[10000000];

void build(int n, int start, int end) {
        int l = n * 2, r = l + 1;
        int mid = (start + end) / 2;
        if(start == end) {
                tree[n] = a[start];
                return;
        }
        build(l, start, mid);
        build(r, mid + 1, end);
        tree[n] = min(tree[l], tree[r]);
}
 
void upd(int n, int start, int end, int idx, int val) {
        if(start == idx and end == idx) {
                tree[n] = val;
                return;
        }
        int mid = (start + end) / 2;
        int l = n * 2, r = l + 1;
        if(idx >= start and idx <= mid) upd(l, start, mid, idx,  val);
        else if(idx >= mid + 1 and idx <= end) upd(r, mid + 1, end, idx, val);
        tree[n] = min(tree[l], tree[r]);
}
 
int query(int n, int start, int end, int i, int j) {
        if(i > end or j < start) return LLONG_MAX;
        if(start >= i and end <= j) return tree[n];
        int l = n * 2, r = l + 1;
        int mid = (start + end) / 2;
        return min(query(l, start, mid, i, j), query(r, mid + 1, end, i, j));
}
 
void solve() {
        
        int n, m; 
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];
        build(1, 1, n);
        for(int i = 0; i < m; i++) {
                int x; cin >> x;
                if(x == 1) {
                        int idx; cin >> idx;
                        int val; cin >> val;
                        upd(1, 1, n, idx, val);
                } else {
                        int i, j; cin >> i >> j;
                        cout << query(1, 1, n, i, j) << endl;
                }
        }
        
}
 
signed main() {
 
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif 
        solve();
        return 0;
}
