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
    int coe = (int)(s[s.length() - 1 - i] - '0');
    sum += base * coe;
    if(base >= 1000000000000000000 / n + 1 && i != s.length()-1){
      return -1;
    }else{
      base *= n;
    }
  }
  return sum;
}

int main() {
  string x;
  ll m;
  cin >> x;
  cin >> m;

  if(x.length() == 1){
    if(stoi(x) <= m){
      cout << 1 << endl;
    }else{
      cout << 0 << endl;
    }
    return 0;
  }
  char maxc = '0';
  rep(i,x.length()){
    maxc = max(maxc, x[i]);
  }
  int mx = (int)(maxc - '0');
  int ans = 0;
  ll l = mx, r = m+1;
  
  while(r-l > 1){
    ll cen = (r+l) / 2;
    ll y = ragix(x, cen);
    if(y == -1){
      r = cen;
      continue;
    }
    if(y <= m){
      l = cen;
    }else{
      r = cen;
    }
  }
  
  cout << l - mx << endl;
  return 0;
}