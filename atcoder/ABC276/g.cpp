#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0;i<(n);i++)
#define rep1(i,n) for (ll i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

const int MAX = 20000005;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    COMinit();
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    rep(s,3){
        rep(i,n){
            ll sum = s + i + 2*(n-1-i);
            ll rem = m - sum;
            if(rem < 0) continue;
            ans += COM(n+rem/3, rem/3) * COM(n-1,i);
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
