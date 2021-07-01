#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n, q;
  cin >> n >> q;

  vector<ll> a(n);
  vector<ll> una(n);

  rep(i,n){
    cin >> a[i];
    una[i] = a[i] - i - 1;
  }

  rep(i,q){
    ll k;
    cin >> k;
    int pos = lower_bound(una.begin(), una.end(), k) - una.begin();
    if(pos == 0){
      cout << k << endl;
    }else{
      cout << a[pos-1] + k - una[pos-1] << endl;
    }
  }
  

  return 0;
}