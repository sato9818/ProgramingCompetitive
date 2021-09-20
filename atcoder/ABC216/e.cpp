#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<ll> a(n+1,0);
  vector<ll> def(n);

  rep(i,n){
    cin >> a[i];
  }

  sort(a.rbegin(), a.rend());

  rep(i,n){
    def[i] = a[i] - a[i+1];
  }

  ll sum = 0;

  rep(i,n){
    if((ll)(i+1) * def[i] <= k){
      sum += (ll)(i+1) * (a[i] + a[i] - def[i] + 1) * def[i] / 2;
      k -= (ll)(i+1) * def[i];
    }else{
      ll quo = k / (i+1);
      ll rem = k % (i+1);
      sum += (ll)(i+1) * (a[i] + a[i] - quo + 1) * quo / 2;
      sum += (ll)rem * (a[i] - quo);
      break;
    }
  }
  cout << sum << endl;
  
  return 0;
}
