#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n;
    cin >> n;

    vector<int> ix{1,0,-1}, iy{1,0,-1};
    vector<P> grids(n);

    set<P> grids_set;

    rep(i,n){
        int x,y;
        cin >> x >> y;
        grids[i] = P(x,y);
        grids_set.insert(grids[i]);
    }

    int ans = 0;

    rep(i,n){
        P grid = grids[i];
        if(grids_set.count(grid)==0){
            continue;
        }
        ans++;
        queue<P> q;
        q.push(grid);
        grids_set.erase(grid);
        while(!q.empty()){
            P p = q.front(); q.pop();
            int x = p.first;
            int y = p.second;
            rep(i,3){
                rep(j,3){
                    if(ix[i]+iy[j] == 0){
                        continue;
                    }
                    if(grids_set.count(P(x + ix[i], y+iy[j])) > 0){
                        q.push(P(x + ix[i], y+iy[j]));
                        grids_set.erase(P(x + ix[i], y+iy[j]));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
