#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;


// a * x = tar (mod MOD)
// のxを求める
// a, tar, MODはそれぞれ互いに素である必要がある

// mod_inv(x / gcd(x,sum), sum / gcd(x,sum))
// ↑こんな感じで使う
ll ext_gcd(ll a, ll b, ll &x, ll &y, ll tar)
{
  if (b == 0)
  {
    x = tar;
    y = 0;
    return a;
  }

  ll d = ext_gcd(b, a % b, y, x, tar);
  y -= a / b * x;
  return d;
}

ll mod(ll a, ll m)
{
  return (a % m + m) % m;
}

ll mod_inv(ll a, ll tar)
{
  ll x, y;
  ll g = ext_gcd(a, MOD, x, y, tar);
  return mod(x, MOD / g);
}

const int MAX = 2000005;
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
    int n, p;
    cin >> n >> p;

    COMinit();

    ll critical = mod_inv(100 / gcd(100,p), p / gcd(100,p));
    ll normal = mod_inv(100 / gcd(100,100-p), (100-p) / gcd(100,100-p));
    // cout << critical << endl;
    // cout << normal << endl;

    ll ans = 0;

    vector<ll> one(n), two(n);
    one[0] = 1;
    two[0] = 1;

    rep1(i,n+1){
        one[i] = one[i-1] * normal % MOD;
        two[i] = two[i-1] * critical % MOD;
    }
    
    rep(i,n/2+1){
        // cout << i << ':' << n-i*2 << ":" << COM(n-i, i) << endl;
        ll add = COM(n-i, i) * one[n-i*2] %MOD * two[i] % MOD * (n-i) % MOD;
        // cout << add << endl;
        ans += add;
        ans %= MOD;
    }

    n = n-1;

    rep(i,n/2+1){
        // cout << i << ':' << n-i*2 << ":" << COM(n-i, i)<< endl;
        ll add = COM(n-i, i) * one[n-i*2] % MOD * two[i] % MOD * critical % MOD * (n-i+1) % MOD;
        // cout << add<< endl;
        ans += add;
        ans %= MOD;
    }

    cout << ans << endl;


    return 0;
}
