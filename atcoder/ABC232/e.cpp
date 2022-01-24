#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  sx--; sy--; gx--; gy--;

  vector<ll> dp(4,0);
  if(sx == gx && sy == gy){
    dp[0] = 1;
  }else if(sx == gx){
    dp[1] = 1;
  }else if(sy == gy){
    dp[2] = 1;
  }else{
    dp[3] = 1;
  }
  rep(i,k){
    vector<ll> dp2(4,0);
    rep(j,4){
      dp2[0] = (dp[1] + dp[2]) % MOD;
      dp2[1] = (dp[0] * (w-1) + dp[1] * (w-2) + dp[3]) % MOD;
      dp2[2] = (dp[0] * (h-1) + dp[2] * (h-2) + dp[3]) % MOD;
      dp2[3] = (dp[1] * (h-1) + dp[2] * (w-1) + dp[3] * (h + w - 4)) % MOD;; 
    }
    swap(dp,dp2);
  }
  cout << dp[0] << endl;
  
  return 0;
}
