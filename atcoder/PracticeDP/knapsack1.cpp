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
    
    rep(i,W+1){
        dp[0][i] = 0;
    }

    rep(i,N){
        rep(j,W+1){
            if(j < w[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            }
        }      
    }
    
    cout << dp[N][W] << endl;
    
    return 0;
}