#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

ll dp[105][105][105];
// j番目まで見て、i個使ってできた和をdで割った余りがkである最大値

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    // vector<vector<int>> cnt(d);

    // rep(i,n){
    //     cnt[a[i]%d].push_back(a[i]);
    // }

    rep(i,k+1){
        rep(j,n+1){
            rep(k,d){
                dp[i][j][k] = -1;
            }
        }
    }

    rep(j,n+1) dp[0][j][0] = 0;
    // dp[0][0][0] = 0;
    
    rep1(i,k+1){
        rep1(j,n+1){
            rep(k,d){
                 dp[i][j][((ll)k + a[j-1]) % d] = dp[i][j-1][((ll)k + a[j-1]) % d];
                if(dp[i-1][j-1][k] == -1) continue;
                dp[i][j][((ll)k + a[j-1]) % d] = max(dp[i][j][((ll)k + a[j-1]) % d], dp[i-1][j-1][k] + a[j-1]);
            }
        }
    }

    // rep1(i,k+1){
    //     rep1(j,n+1){
    //         rep(k,d){
    //             cout << i << ":" << j << ":" << k << ": " << dp[i][j][k] << endl;
    //         }
    //     }
    // }
    cout << dp[k][n][0] << endl;

    return 0;
}
