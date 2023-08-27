#include <iostream>
#include <vector>
#include <map>
using namespace std;
 
int save[1010][1010];
 
void build(int n) {
        int tot = 0;
        for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                        tot += save[i][j];
                        save[i][j] = tot;
                        save[i][j] -= save[i-1][n] - save[i-1][j];
                }
        }
        
}
 
 
void solve() {
        
        int n, q; cin >> n >> q;
        
        for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                        char x; cin >> x;
                        if(x == '*') save[i][j] = 1;
                }
        }
        
        build(n);
        
        while(q--) {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                
                int ans = save[x2][y2] - save[x2][y1-1] - save[x1-1][y2] + save[x1-1][y1-1];
                
                cout << ans << endl;
        }
        
}
 
signed main() {
        solve();
        return 0;
}
