#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  vector<ll> dp(3001,0);
  if(a[0] == 0){
    dp[0] = 1;
  }
  rep1(i,3001){
    if(a[0] <= i && i <= b[0]){
      dp[i] = dp[i-1] + 1;
    }else if (a[0] > i){
      dp[i] = 0;
    }else if(i > b[0]){
      dp[i] = dp[i-1];
    }
  }

  // rep(i,5){
  //   cout << dp[i] << endl;
  // }
  rep1(i,n){
    vector<ll> dp2(3001,0);
    if(a[i] == 0){
      dp2[0] = dp[0];
    }
    rep1(j,3001){
      
      if(j >= a[i] && j <= b[i]){
        dp2[j] = (dp2[j-1] + dp[j]) % MOD;
      }else{
        dp2[j] = dp2[j-1];
      }
    }
    swap(dp, dp2);
  }

  // ll ans = 0;
  // rep(i,3001){
  //   ans = (ans + dp[i]) % MOD;
  // }
  cout << dp[3000] << endl;

  return 0;
}
