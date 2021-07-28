#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,a,x,y;
  cin >> n >> a >> x >> y;

  if(n > a){
    cout << (n-a) * y + a * x << endl;
  }else{
    cout << n * x << endl;
  }
  return 0;
}
