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
    string s;
    cin >> s;

    vector<vector<ll>> dp(n,vector<ll>(2,0));
    dp[0][s[0] - '0'] = 1;
    ll sum = 0;
    rep1(i,n){
        if(s[i] == '1'){
            dp[i][0] += dp[i-1][1];
            dp[i][1] += dp[i-1][0]+1;
        }else if(s[i] == '0'){
            dp[i][1] += dp[i-1][1] + dp[i-1][0];
            dp[i][0] ++;
        }
    }

    rep(i,n){
        sum += dp[i][1];
    }

    cout << sum << endl;


    return 0;
}
// 0: 101
// 1: 010