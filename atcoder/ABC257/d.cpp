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
    vector<vector<int>> points(n, vector<int>(3));
    vector<vector<ll>> costs(n,vector<ll>(n,0));

    rep(i,n){
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }

    auto dis = [&](int i, int j){
        return (ll)abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
    };

    auto cost = [&](int i, int j){
        return ceil((double)dis(i,j) / points[i][2]);
    };

    rep(i,n){
        rep(j,n){
            costs[i][j] = cost(i,j);
            // cout << i << ":" << j << ":" << costs[i][j] << endl;
        }
    }
    
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                costs[i][j] = min(costs[i][j], max(costs[i][k], costs[k][j]));
                
            }
        }
    }

    ll ans = LINF;

    rep(i,n){
        ll mx = 0;
        rep(j,n){
            mx = max(mx, costs[i][j]);
            
        }
        // cout << i << ":" << mx << endl;
        ans = min(mx, ans);
    }

    
    cout << ans << endl;

    return 0;
}
