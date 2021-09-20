#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  ll sum = 0;

  sum += a * (100 - a);
  sum += b * (100 - b);
  sum += c * (100 - c);

  double ans = (double)sum / (a+b+c);

  cout << ans << endl;

  
  return 0;
}
