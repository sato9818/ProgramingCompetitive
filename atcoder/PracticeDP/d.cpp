// knapsack 一つのvectorでやる

#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> w(n),v(n);
  vector<ll> dp(W+1,0);
  
  rep(i,n){
    cin >> w[i] >> v[i];    
  }
  rep(i,n){
    vector<ll> buf(W+1,0);
    rep1(j,W+1){
      if(j < w[i]){
        buf[j] = dp[j];
      }else{
        buf[j] = max(dp[j], dp[j-w[i]] + v[i]);
      }
    }
    swap(buf, dp);
  }
  cout << dp[W] << endl;
    
  return 0;
}