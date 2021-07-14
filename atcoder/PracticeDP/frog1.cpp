#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> h(N+1);
    vector<int> dp(N+1);
    
    rep(i,N){
        cin >> h[i+1];    
    }
    h[0] = h[1];
    dp[0] = 0;
    dp[1] = 0;
    for(int i=2;i<N+1;i++){
        dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
    }
    
    cout << dp[N] << endl;
    
    return 0;
}