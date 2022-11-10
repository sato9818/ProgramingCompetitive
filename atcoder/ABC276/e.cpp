#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

vector<int> ix{0,1,0,-1}, iy{1,0,-1,0};
int ans = 0;

map<P,int> mx;

void dfs(int x, int y, vector<string>& grid, set<P>& visited){
    // cout << x << ":" << y << endl;
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
        return;
    }
    if(grid[x][y] == '#') return;
    if(grid[x][y] == 'S') {
        if(visited.size() >= 4) ans = 1;
        return;
    }
    
    if(mx.count(P(x,y)) > 0 && mx[P(x,y)] >= visited.size()){
        return;
    }
    // cout << x << ":" a<< y << endl;
    mx[P(x,y)] = visited.size();

    rep(i,4){
        if(visited.find(P(x+ix[i], y+iy[i])) != visited.end()){
            continue;
        }
        visited.insert(P(x+ix[i], y+iy[i]));
        dfs(x+ix[i], y+iy[i], grid, visited);
        visited.erase(P(x+ix[i], y+iy[i]));
    }
}

int main() {
    int h,w;
    cin >> h >> w;

    vector<string> grid(h);

    rep(i,h){
        cin >> grid[i];
    }

    int sx = 0, sy = 0;

    rep(i,h){
        rep(j,w){
            if(grid[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }

    set<P> visited;
    rep(i,4){
        visited.insert(P(sx+ix[i], sy+iy[i]));
        dfs(sx+ix[i], sy+iy[i], grid, visited);
        visited.erase(P(sx+ix[i], sy+iy[i]));
    }


    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
