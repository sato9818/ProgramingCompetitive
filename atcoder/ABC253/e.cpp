#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const ll MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> dp(m+1);
    vector<ll> sum(m+1,0);
    rep1(i,m+1){
        dp[i] = 1;
        sum[i] = dp[i] + sum[i-1];
    }
    
    rep(i,n-1){
        vector<ll> dp2(m+1,0);
        rep1(j,m+1){
            if(k==0){
                dp2[j] = sum[m];
            }else{
                if(j + k <= m){
                    dp2[j] += sum[m] - sum[j+k-1];
                }
                if(j - k >= 1){
                    dp2[j] += sum[j-k];
                }
            }
        }
        rep1(j,m+1){
            sum[j] = dp2[j] + sum[j-1] + MOD;
            sum[j] %= MOD;
        }
        swap(dp,dp2);
        // if(sum[m] < 0){
        //     cout << i << endl;
        // }
    }
    cout << sum[m] << endl;

    return 0;
}
