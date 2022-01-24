#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 100000;
int dp[301][301][301];

int main() {
  int n;
  cin >> n;
  int x,y;
  cin >> x >> y;
  // dp[i][j][k] = when we can use i lunchboxee, how many lunchboxes do we need to have j takoyakis and k taiyakis.
  
  vector<P> l(n);
  
  rep(i,n){
    int a,b;
    cin >> a >> b;
    l[i] = P(a,b);
  }
  
  rep(i,n+1){
    rep(j, 301){
      rep(k, 301){
        dp[i][j][k] = INF;
      }
    }
  }

  dp[0][0][0] = 0;
  rep1(i,n+1){
    int a,b;
    a = l[i-1].first;
    b = l[i-1].second;

    rep(j,301){
      rep(k, 301){
        if(j == 0 && k == 0){
          dp[i][j][k] = 0;
          continue;
        }
        if(j-a < 0 && k-b < 0){
          dp[i][j][k] = 1;
        }else if(j-a < 0){
          dp[i][j][k] = min(dp[i-1][0][k-b] + 1, dp[i-1][j][k]);
        }else if(k-b < 0){
          dp[i][j][k] = min(dp[i-1][j-a][0] + 1, dp[i-1][j][k]);
        }else{
          dp[i][j][k] = min(dp[i-1][j-a][k-b] + 1, dp[i-1][j][k]);
        }
        // if(dp[i][j][k] != INF) cout << dp[i][j][k] << " j: " << j << " k: " << k << endl;
      }
    }
  }
  if(dp[n][x][y] == INF){
    cout << -1 << endl;
  }else{
    cout << dp[n][x][y] << endl;
  }
  return 0;
}
