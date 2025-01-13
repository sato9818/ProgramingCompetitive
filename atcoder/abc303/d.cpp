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
    ll x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;

    vector<vector<ll>> dp(s.size()+1, vector<ll>(2, 0));
    dp[0][1] = z;
    rep(i,s.size()){
        char ch = s[i];
        if(ch == 'a') {
            dp[i+1][0] = min(dp[i][0] + min(x, z*2 + y), dp[i][1] + min(z + x, y+z));
            dp[i+1][1] = min(dp[i][1] + min(y, z*2 + x), dp[i][0] + min(x+z, y+z));
        }else{
            dp[i+1][0] = min(dp[i][0] + min(y, z*2 + x), dp[i][1] + min(z + x, y+z));
            dp[i+1][1] = min(dp[i][1] + min(x, z*2 + y), dp[i][0] + min(z + y, x+z));
        }
        // cout << dp[i+1][0] << " " << dp[i+1][1] << endl;
    }


    cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;

    return 0;
}
