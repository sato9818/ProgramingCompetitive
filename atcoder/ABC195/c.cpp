#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  ll com = 1000;
  ll cnt = 0;

  while(n >= com){
    cnt += n - (com - 1);
    com *= 1000;
  }

  cout << cnt << endl;
  
  return 0;
}