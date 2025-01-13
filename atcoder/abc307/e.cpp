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
    int n, m;
    cin >> n >> m;
    ll sum = 1;
    ll zero = 1;
    rep(i,n-1) {
        zero = ((sum - zero) + MOD) % MOD;
        sum = sum * (m-1) % MOD;
    }

    // cout << sum << endl;
    // cout << zero << endl;

    cout << ((sum - zero + MOD) * m % MOD) << endl;

    return 0;
}
