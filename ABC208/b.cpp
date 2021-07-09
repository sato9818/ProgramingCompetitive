#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int p;
  cin >> p;

  vector<int> fac(11,1);

  rep1(i,11){
    fac[i] *= i * fac[i-1];
  }

  int ans = 0;
  int ind = 10;
  while(true){
    if(p==0){
      break;
    }
    if(p >= fac[ind]){
      p -= fac[ind];
      ans++;
    }else{
      ind--;
    }
  }

  cout << ans << endl;

  return 0;
}