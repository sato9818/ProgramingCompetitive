#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> c(n),v(n);
  vector<int> dp(n*1000 + 1,INF);
  
  rep(i,n){
    cin >> c[i] >> v[i];    
  }

  rep(i,n){
    vector<int> buf(n*1000 + 1,0);
    rep(j,n*1000 + 1){
      if(j <= v[i]){
        buf[j] = min(dp[j], c[i]);
      }else{
        buf[j] = min(dp[j], dp[j-v[i]] + c[i]);
      }
    }
    swap(buf, dp);
  }
  rep(i,n*1000 + 1){
    if(dp[n*1000 - i] <= w){
      cout << n*1000 - i << endl;
      return 0;
    }
  }
  
  return 0;
}