#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int sum = 0;

  rep(i,n){
    cin >> v[i];
    sum += v[i];
  }
  const int MAX_SIZE = 100005;
  vector<bool> dp(MAX_SIZE, false);
  dp[0] = true;
  dp[v[0]] = true;

  rep1(i,n){
    vector<bool> dpx(MAX_SIZE);
    rep(j,MAX_SIZE){
      dpx[j] = dp[j];
      if(j-v[i] >= 0){
        dpx[j] = dpx[j] || dp[j-v[i]];
      }
    }
    swap(dp,dpx);
  }

  for(int i = ceil(sum/2.0);i<=sum;i++){
    if(dp[i]){
      cout << i << endl;
      break;
    }
  }

  return 0;
}