#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  P a = min(make_pair(1,4),make_pair(2,5));
  P b = numeric_limits<P>::max();
  cout << b.first << endl;
  cout << b.second << endl;
  return 0;
}