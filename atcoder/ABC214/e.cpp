#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector< vector<int> > g(n);

  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  // rep(i,n){
  //   rep(j,g[i].size()){
  //     cout << i << " " << g[i][j] << endl;
  //   }
  // }

  vector<ll> dp(n,0);
  dp[0] = 1;
  ll sum = 1;

  rep(i,k){
    vector<ll> buf(n,0);
    ll bufSum = 0;
    rep(j,n){
      buf[j] = (sum + MOD - dp[j]) % MOD;
      rep(k,g[j].size()){
        buf[j] = (buf[j] + MOD - dp[g[j][k]]) % MOD;
      }
      bufSum = (bufSum + buf[j]) % MOD;
    }
    swap(dp,buf);
    sum = bufSum;
  }

  cout << dp[0] << endl;

  
  return 0;
}
