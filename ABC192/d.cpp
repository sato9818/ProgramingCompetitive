#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll ragix(string s, ll n){
  ll sum = 0;
  ll base = 1;
  rep(i,s.length()){
    sum += base * (int)(s[s.length() - 1 - i] - '0');
    if(base > 1000000000000000000){
      return -1;
    }
    base *= n;
  }
  return sum;
}

int main() {
  string x;
  ll m;
  cin >> x;
  cin >> m;

  char maxc = '0';
  rep(i,x.length()){
    maxc = max(maxc, x[i]);
  }
  int mx = (int)(maxc - '0');
  int ans = 0;
  if(y.length() < 4){
    for(ll j = sqrt(m); j>0;j--){
      ll y = ragix(x, j);
      if(y <= m){
        cout << j-mx << endl;
        return 0;
      }
    }
  }else{
    for(ll j = mx+1;;j++){
      ll y = ragix(x, j);
      if(y == -1){
        cout << ans << endl;
        return 0;
      }
      if(y <= m){
        ans++;
      }else{
        cout << ans << endl;
        return 0;
      }
    }
  
  }
  
  cout << ans << endl;
  return 0;
}