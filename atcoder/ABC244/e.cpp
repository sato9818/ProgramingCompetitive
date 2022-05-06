#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

ll dp[2005][2005][2];

int main() {
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    x--; s--; t--;
    vector<vector<int>> e(n);
    vector<int> hasx(n,0);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if(u == x){
            hasx[v] = 1;
        }else if(v == x){
            hasx[u] = 1;
        }
        e[u].push_back(v);
        e[v].push_back(u);
    }

    rep(i,k+1){
        rep(j,n){
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    
    dp[0][s][0] = 1;

    rep(i,k){
        rep(j,n){
            for(auto node : e[j]){
                if(node == x){
                    dp[i+1][node][1] = (dp[i+1][node][1] + dp[i][j][0]) % MOD;
                    dp[i+1][node][0] = (dp[i+1][node][0] + dp[i][j][1]) % MOD;
                }else{
                    dp[i+1][node][0] = (dp[i+1][node][0] + dp[i][j][0]) % MOD;
                    dp[i+1][node][1] = (dp[i+1][node][1] + dp[i][j][1]) % MOD;
                }
            }
        }
    }

    cout << dp[k][t][0] << endl; 
    return 0;
}
