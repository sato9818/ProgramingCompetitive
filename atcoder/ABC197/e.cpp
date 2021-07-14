#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  const int INF = 1001001001;
  vector<int> x(n);
  vector<int> c(n);
  vector<int> r(n, -INF), l(n, INF);

  rep(i,n){
    cin >> x[i] >> c[i];
  }

  rep(i,n){
    r[c[i]-1] = max(x[i], r[c[i]-1]);
    l[c[i]-1] = min(x[i], l[c[i]-1]);
  }

  // 0がright,1がleft
  vector<ll> dp(2,0);
  int rx = 0, lx = 0;
  for(int i=0;i<n;i++){
    if(r[i] != -INF){
      vector<ll> dp_buf(2);
      dp_buf[0] = min(dp[0] + abs(rx - l[i]) + abs(r[i] - l[i]), dp[1]+ abs(lx - l[i]) + abs(r[i] - l[i]));
      dp_buf[1] = min(dp[0] + abs(rx - r[i]) + abs(r[i] - l[i]), dp[1]+ abs(lx - r[i]) + abs(r[i] - l[i]));
      rx = r[i];
      lx = l[i];
      swap(dp, dp_buf);
    }
  }

  cout << min(dp[0] + abs(rx), dp[1] + abs(lx)) << endl;;
  
  return 0;
}