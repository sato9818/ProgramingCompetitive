#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

class BIT {
public:
    //データの長さ
    ll n;
    //データの格納先
    vector<ll> a;
    //コンストラクタ
    BIT(ll n):n(n),a(n+1,0){}

    //a[i]にxを加算する
    void add(ll i,ll x){
        i++;
        if(i==0) return;
        for(ll k=i;k<=n;k+=(k & -k)){
            a[k]+=x;
        }
    }

    //a[i]+a[i+1]+…+a[j]を求める
    ll sum(ll i,ll j){
        return sum_sub(j)-sum_sub(i-1);
    }

    //a[0]+a[1]+…+a[i]を求める
    ll sum_sub(ll i){
        i++;
        ll s=0;
        if(i==0) return s;
        for(ll k=i;k>0;k-=(k & -k)){
            s+=a[k];
        }
        return s;
    }
};

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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll mx = 0;
    rep(i,n) mx = max(a[i], mx);
    BIT bit(mx+1), cnt(mx+1);

    ll sum = 0;

    rep(i,n) {
        // cout << bit.sum(a[i]+1, mx) << endl;
        sum += bit.sum(a[i]+1, mx) % MOD * 2 + a[i];
        sum %= MOD;
        // cout << cnt.sum(1, a[i]) << endl;
        sum += cnt.sum(1, a[i]) * 2 * a[i];
        // cout << (i+1)*(i+1) << ":" << sum << endl; 
        ll x = (ll)(i+1)*(i+1) % MOD;
        sum %= MOD;
        cout << mod_inv(x / gcd(x,sum), sum / gcd(x,sum)) << endl;
        bit.add(a[i], a[i]);
        cnt.add(a[i], 1);
    }

    return 0;
}
