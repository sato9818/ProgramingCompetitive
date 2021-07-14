#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  double x0, y0, xh, yh;
  cin >> x0 >> y0;
  cin >> xh >> yh;

  double xc, yc;
  xc = (x0 + xh) / 2;
  yc = (y0 + yh) / 2;

  double x1, y1;

  x1 = (x0 - xc) * cos(2*M_PI / n) - (y0 - yc) * sin(2*M_PI / n) + xc;
  y1 = (x0 - xc) * sin(2*M_PI / n) + (y0 - yc) * cos(2*M_PI / n) + yc;
  cout << x1 << " " << y1 << endl;
  return 0;
}