#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;

int main() {
  ll n;
  cin >> n;
  ll sum = 0;

  if(n == 1){
    cout << 1 << endl;
    return 0;
  }else if(n == 2){
    cout << 3 << endl;
    return 0;
  }else if(n == 3){
    cout << 5 << endl;
    return 0;
  }

  for(ll i=1;i*i<=n;i++){
    sum += n/i;
  }

  for(int i=n/(int)sqrt(n);i>1;i--){
    sum += (n/(i-1) - (n/i)) * (i-1);
  }

  cout << sum << endl;
  return 0;
}
