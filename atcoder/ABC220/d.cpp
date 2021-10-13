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

  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  vector<ll> dp(10,0);
  dp[a[0]] = 1;

  rep1(i,n){
    vector<ll> dpbuf(10,0);
    rep(j,10){
      dpbuf[(j+a[i]) % 10] += dp[j];
      dpbuf[(j*a[i]) % 10] += dp[j];
    }
    rep(j,10){
      dpbuf[j] %= MOD;
    }

    swap(dp,dpbuf);
  }

  rep(i,10){
    cout << dp[i] << endl;
  }


  return 0;
}
