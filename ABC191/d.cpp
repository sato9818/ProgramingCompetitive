#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  long double x,y,r;
  cin >> x >> y >> r;
  ll st = ceil(x - r);
  ll end = floor(x + r);
  r = nextafter(r,INFINITY);
  
  ll sum = 0;
  for(ll i = st;i<end+1;i++){
    long double buf = sqrt(r * r - (i - x) * (i - x));
    sum += (ll)floor(y + buf) - (ll)ceil(y - buf) + 1;
  }
  cout << sum << endl;
  return 0;
}