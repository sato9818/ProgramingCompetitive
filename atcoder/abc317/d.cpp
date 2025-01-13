#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

// dp[i][j]: i個目の選挙区でj個獲得議席を取るために必要な最小裏切り数

ll dp[105][100005];

int vote(int x, int y) {
    if(x > y) return 0;
    return (x + y) / 2 + 1 - x;
}

int main() {
    int n;
    cin >> n;

    ll sum_seats = 0;

    vector<int> takahashi(n), aoki(n), seats(n);

    rep(i,n){
        cin >> takahashi[i] >> aoki[i] >> seats[i];
        sum_seats += seats[i];
    }

    rep(i,105) rep(j,100005) dp[i][j] = LINF;
    dp[0][0] = 0;

    rep(i,n) {
        int v = vote(takahashi[i], aoki[i]);
        rep(j, 100005) {
            dp[i+1][j] = dp[i][j];
        }
        rep(j,100005) {
            if(seats[i] + j >= 100001) break;
            dp[i+1][seats[i]+j] = min(dp[i+1][seats[i]+j], dp[i][j] + v);
            // if(dp[i+1][seats[i]+j] != LINF)
            // cout << v << endl;
        }
    }

    ll ans = LINF;
    for(int i = sum_seats / 2 + 1; i <= sum_seats; ++i) {
        // cout << dp[n][i] << endl;
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;

    return 0;
}
