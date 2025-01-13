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
    int h,w,n;
    cin >> h >> w >> n;
    vector<vector<int>> hole(h, vector<int>(w,0));
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        hole[a][b] = 1;
    }

    vector<vector<ll>> dp(h, vector<ll>(w,0));

    rep(i,h){
        if(hole[i][0]) continue;
        dp[i][0] = 1;
    }
    rep(i,w){
        if(hole[0][i]) continue;
        dp[0][i] = 1;
    }
    rep1(i,h)rep1(j,w){
        if(hole[i][j]) continue;
        dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
    }

    ll ans = 0;
    rep(i,h)rep(j,w){
        ans += dp[i][j];
    }
    
    cout << ans << endl;

    return 0;
}
