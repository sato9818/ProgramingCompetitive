#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  int mx = 0;
  const int mod = 998244353;
  vector<ll> a(n);

  ll ans = 0;

  rep(i,n){
    cin >> a[i];
    ans = (ans + a[i]*a[i]%mod) % mod;
  }
  
  sort(a.begin(), a.end());
  
  
  ll sub_sum = 0;
  rep1(i,n){
    sub_sum = sub_sum * 2 % mod;
    sub_sum += a[n-i];

    ans = (ans + sub_sum * a[n-i-1] % mod) % mod;
  }

  cout << ans << endl;
  
  return 0;
}