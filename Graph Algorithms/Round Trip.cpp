#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
const int MAX = 1e6 + 10;
vector <int> g[MAX];
int n, m;
int mark[MAX];
int par[MAX];
int start = 0, last = 0;
 
void dfs(int u, int p) {
        mark[u]++; par[u] = p;
        for(int i: g[u]) {
                if(mark[i]==0) dfs(i, u);
                else {
                        if(i!=p and start == 0 and last == 0) {
                                start = u; 
                                last = i;
                        }
                }
        }
        
        
}
 
 
void solve() {
        cin >> n >> m;
        for(int i=0; i<m; i++) {
                int u, v; cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
        }
        
        
        
        for(int i  = 1; i <= n; i++) {
 
                if(mark[i] == 0) dfs(i, 1);
 
                if(start != 0) {
 
                        vector <int> ans;
        
                        int x = start; 

                        while(1) {
                                if(start == last) break;
                                ans.push_back(start);
                                start = par[start];
                        }
                        ans.push_back(last);
                        ans.push_back(x);
                        cout << ans.size() << endl;
                        for(auto i:ans) cout<<i<<" ";
                        return;
                }
 
 
        }
 
 
        cout<<"IMPOSSIBLE\n";
}
 
signed main() {
 
 
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif 
        solve(); return 0;
}
