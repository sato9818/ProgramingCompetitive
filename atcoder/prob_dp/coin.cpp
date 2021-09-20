#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

double dp[105][105] = {0};

int main() {
  int n,k;
  cin >> n >> k;
  dp[0][0] = 1;

  rep(i,n){
    dp[i+1][0] += dp[i][0] / 2;
    rep1(j,101){
      dp[i+1][j+1] += dp[i][j] / 2;
      dp[i+1][0] += dp[i][j] / 2;
    }
  }


  double ans = 0;

  for(int i=k;i<101;i++){
    ans += dp[n][i];
  }
  // rep(i,k){
  //   cout << dp[n][i] << endl;
  //   ans += dp[n][i];
  // }
  cout << ans*2 << endl;
  
  return 0;
}
