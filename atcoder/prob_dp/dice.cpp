#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

double dp[101][101] = {0};

int main() {
  int n,k;
  cin >> n >> k;
  dp[0][0] = 1;
  
  rep(i,n){
    rep(j,101){
      rep1(l,7){
        dp[i+1][j+l] += dp[i][j] * ((double)1/6);
      }
    }
  }
  
  double ans = 0;

  for(int i=k;i<101;i++){
    ans += dp[n][i];
  }
  rep1(i,7){
    cout << dp[1][i] << endl;
  }

  cout << ans << endl;
  
  
  return 0;
}
