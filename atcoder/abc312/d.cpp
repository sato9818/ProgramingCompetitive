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
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[0][0] = 1;
    rep1(i,n+1){
        rep(j,n){
            if(str[i-1] == '(') {
                dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
            } else if(str[i-1] == ')') {
                if(j-1 >= 0) dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MOD;
            } else {
                dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % MOD;
                if(j-1 >= 0) dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % MOD;
            }
        }
    }

    // rep1(i,n+1) {
    //     rep(j,n) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n][0] << endl;

    return 0;
}
