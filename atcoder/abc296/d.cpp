#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    ll n,m;
    cin >> n >> m;
    ll ans = LINF;

    ll a = min((ll)1000000, n);
    rep1(i,a+1){
        ll b = ceil(1.0*m/i);
        if(b > n) continue;
        ans = min(ans, i * b);
    }

    if(ans == LINF) cout << -1 << endl;
    else cout << ans << endl;



    return 0;
}
