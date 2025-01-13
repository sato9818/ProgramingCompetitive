#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

// dp[i][j][k]: i回目にtakahashiがjにいて、aokiがkにいるときの数


// a * x = tar (mod MOD)
// のxを求める
// a, tar, MODはそれぞれ互いに素である必要がある

// mod_inv(x / gcd(x,tar), tar / gcd(x,tar))
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
ll dp[105][205][205][2];
int main() {
    int n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;

    

    dp[0][a][b][0] = 1;
    rep(i,n+1) {
        rep(j,n){
            rep(k,n){
                rep(l,p){
                    dp[i+1][min(j+l+1,n)][k][1] += dp[i][j][k][0] * mod_inv(p, 1) % MOD;
                    dp[i+1][min(j+l+1,n)][k][1] %= MOD;
                    // if(dp[i+1][min(j+l+1,n)][k][1])
                }
                rep(l,q){
                    dp[i+1][j][min(k+l+1,n)][0] += dp[i+1][j][k][1] * mod_inv(q, 1) % MOD;
                    dp[i+1][j][min(k+l+1,n)][0] %= MOD;
                }
                // if(dp[i][j][k] == 0) continue;
                // cout << "i:" << i << " j:" << j << " k:" << k << endl;
                // cout << dp[i][j][k] << endl;
            }
        }
    }
    ll taka = 0, ao = 0;
    rep(i,n){
        rep(j,n){
            // cout << "i:" << i << " j:" << j << endl;
            // cout << dp[i][j][n][0] << endl;
            taka += dp[i][n][j][1];
            taka %= MOD;
        }
    }
    // ll sum = taka + ao;
    // cout << taka << ":" << ao << endl;
    cout <<  taka << endl;

    return 0;
}
// dp[0][2][3][0] = 1;

// dp[1][3][3][1] = 1;
// dp[1][4][3][1] = 2;

// dp[1][3][4][0] = 2;
// dp[1][4][4][0] = 1;
// dp[1][4][5][0] = 1;
// dp[1][5][4][0] = 1;
// dp[1][5][5][0] = 1;
// (1,1)(1,2)(2,1)(2,2)(3,1)(3,2)


// 2
// 3