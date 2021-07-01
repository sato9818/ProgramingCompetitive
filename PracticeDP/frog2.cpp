#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> h(N);
    vector<int> dp(N, 1001001001);
    
    rep(i,N){
        cin >> h[i];    
    }

    dp[0] = 0;
    
    rep(i,N){
        for(int j=1;j<=K;j++){
            if(j+i>=N){
                break;
            }
            dp[i+j] = min(dp[i+j], dp[i] + abs(h[i+j] - h[i]));
            // cout << "dp[" << i+j << "] = " << dp[i+j] << endl;
        }
    }
    
    cout << dp[N-1] << endl;
    
    return 0;
}