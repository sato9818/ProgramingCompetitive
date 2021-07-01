#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[100001][3];

int main() {
    int N;
    cin >> N;
    vector<int> a(N),b(N),c(N);
    // vector< vector<int> > dp(N);
    
    rep(i,N){
        cin >> a[i] >> b[i] >> c[i];    
    }

    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    
    rep(i,N-1){
        dp[i+1][0] = a[i+1] + max(dp[i][1], dp[i][2]);
        dp[i+1][1] = b[i+1] + max(dp[i][0], dp[i][2]);
        dp[i+1][2] = c[i+1] + max(dp[i][1], dp[i][0]);  
    }
    
    cout << max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2])) << endl;
    
    return 0;
}