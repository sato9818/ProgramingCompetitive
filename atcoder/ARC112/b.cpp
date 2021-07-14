#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll b, c;
  cin >> b >> c;

  ll ans = 0;
  if(b > 0){
    ans += (c - 1) / 2 + (c - 2)/2;
    ll x = (c-1) / 2 + c / 2;
    if(x > b*2-1){
      x = b*2 -1;
    }
    ans += x + 2;
    
  }else if(b < 0){
    ans += (c-1) / 2 + c / 2;;
    ll x = (c - 1) / 2 + (c - 2) / 2;
    if(x > -1*b*2 - 1){
      x = -1*b*2 -1;
    }
    ans += x + 2;
  }else{
    ans += c / 2 + (c - 2)/2 + 1;
  }
  cout << ans << endl;
  return 0;
}