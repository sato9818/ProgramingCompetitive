#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  ll r, x, y;
  cin >> r >> x >> y;
  
  long double dis = sqrt(x*x + y*y);

  if(dis < r){
    cout << 2 << endl;
  }else{
    cout << ceil(dis/r) << endl;
  }

  
  
  return 0;
}