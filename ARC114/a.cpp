#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n){
    cin >> x[i];
  }
  vector<int> prime{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  ll ans = 1001001001001001001; 
  rep(i,1<<15){
    if(i == 0){
      continue;
    }
    ll sum = 1;
    rep(j,15){
      if(i>>j&1){
        sum *= prime[j];
      }
    }
    int flag = 0;
    rep(j,n){
      if(gcd(sum,(ll)x[j]) == 1){
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      ans = min(ans, sum);
    }
  }

  cout << ans << endl;

  return 0;
}