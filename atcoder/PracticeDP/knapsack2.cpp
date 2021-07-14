#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[101][100001];

int main() {
    int N,W;
    cin >> N >> W;
    vector<int> w(N),v(N);
    // vector< vector<int> > dp(N);
    
    rep(i,N){
        cin >> w[i] >> v[i];    
    }
    
    rep(i,100001){
        dp[0][i] = 1001001001001001001;
    }
    dp[0][0] = 0;
    rep(i,N){
        rep(j,100001){
            if(j < v[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
            }
        }      
    }
    int ans = 0;
    rep(i,100001){
        if(dp[N][i] <= W){
            ans = i;
        }
    }
    cout << ans << endl;
    
    return 0;
}