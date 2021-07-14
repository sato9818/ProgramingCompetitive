#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int t;
  cin >> t;
  rep(i,t){
    int l, r;
    cin >> l >> r;
    ll ans = 0, sum = 0;
    if(l*2 > r){
      cout << 0 << endl;
      continue;
    }
    if(r % 2 == 0){
      sum += (r/2 - l) * 2 + 1 ; 
    }else{
      sum += (r/2 + 1 - l) * 2;
    }
    ans = (1 + sum) * sum / 2;
    cout << ans << endl;
  }
  return 0;
}