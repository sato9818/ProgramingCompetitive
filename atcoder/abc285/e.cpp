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
    vector<ll> a(n), sum(n,0);
    rep(i,n) cin >> a[i];
    rep(i,n-1) {
        sum[i+1] += sum[i] + a[i/2];
    }
    // cout << sum[n-1] << endl;
    vector<ll> dp(n+1,0);
    for(int i=2;i<n+1;i++) {
        rep(j, i){
            dp[i] = max(dp[i], dp[j] + sum[i-j-1]);
        }
    }
   
    cout << dp[n] << endl;
    return 0;
}
