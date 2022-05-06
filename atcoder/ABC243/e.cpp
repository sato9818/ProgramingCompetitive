#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
using PP = pair<int, P>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

int main() {
    int n,m;
    cin >> n >> m;

    vector<PP> e(m);
    vector<vector<ll>> cost(n, vector<ll> (n, LINF));
    int ans = 0;

    rep(i,n){
        cost[i][i] = 0;
    }

    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        cost[a][b] = cost[b][a] = c;
        e[i] = PP(c, P(a,b));
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    rep(i,m){
        int a = e[i].second.first;
        int b = e[i].second.second;
        int c = e[i].first;
        int flag = 0;
        rep(j,n){
            if(j == a || j == b){
                continue;
            }
            if(cost[a][j] + cost[j][b] <= c){
                flag = 1;
            }
        }
        if(flag){
            ans++;
        }
    }
  
    cout << ans << endl;
    return 0;
}
