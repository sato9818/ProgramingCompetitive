#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

//  0
// 3 1
//  2 
int visited[1005][1005][4];
void dfs(vector<string>& s, int x, int y, int pre_x, int pre_y, int dir){
    // if(x<0 || y<0 || x>=s.size() || y>=s[0].size()) return;
    // cout << x << " " << y << " " << dir << endl;
    if(visited[x][y][dir]) return;
    
    visited[x][y][dir] = 1;
    if(s[x][y] == '#') {
        rep(i,4) {
            dfs(s, pre_x, pre_y, x, y, i);
        }
        return;
    }
    if(dir == 0) {
        dfs(s, x+1, y, x, y, 0);
    }else if(dir == 1) {
        dfs(s, x, y+1, x, y, 1);
    }else if(dir == 2) {
        dfs(s, x-1, y, x, y, 2);
    }else if(dir == 3) {
        dfs(s, x, y-1, x, y, 3);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> s(n);

    rep(i,n) cin >> s[i];


    rep(i,4){
        dfs(s, 1, 1, -1, -1, i);
    }

    int ans = 0;
    rep(i,n) {
        rep(j,m) {
            rep(k,4) {
                if(visited[i][j][k] && s[i][j] == '.') {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
    


    return 0;
}
