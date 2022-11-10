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
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    map<int,int> mp;
    vector<vector<ll>> dp(n+1, vector<ll>(n+1,-1));

    dp[0][0] = 0;
    rep(i,m){
        int c,y;
        cin >> c >> y;
        mp[c] = y;
    }
    ll prev_max = 0;
    rep1(i,n+1){
        dp[i][0] = prev_max;
        rep(j,n){
            if(dp[i-1][j] != -1){
                dp[i][j+1] = dp[i-1][j] + x[i-1] + (ll)mp[j+1];
                prev_max = max(dp[i][j+1], prev_max);
            }
        }
    }

    cout << prev_max << endl;

    return 0;
}
