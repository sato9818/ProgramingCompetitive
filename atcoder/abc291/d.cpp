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
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    rep(i,n){
        cin >> a[i] >> b[i];
    }

    vector<ll> dpa(n,0), dpb(n,0);
    dpa[0] = 1;
    dpb[0] = 1;


    rep1(i,n){
        if(a[i] != a[i-1]){
            dpa[i] += dpa[i-1];
        }
        if(a[i] != b[i-1]){
            dpa[i] += dpb[i-1];
        }
        if(b[i] != a[i-1]){
            dpb[i] += dpa[i-1];
        }
        if(b[i] != b[i-1]){
            dpb[i] += dpb[i-1];
        }
        dpa[i] %= MOD;
        dpb[i] %= MOD;
    }

    cout << (dpa[n-1] + dpb[n-1]) % MOD << endl;

    return 0;
}
