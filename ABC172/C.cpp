#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int N,M,K;
vector<int> A(200001),B(200001);
int m[200001][200001];

int solve(int i, int j, int k){
    if (m[i][j] >=0){
        return m[i][j];

    }
    if(k < 1 || (A[i]>k && B[i]>k)){
        return 0;
    }
    cout << i << " " << j << " "<< k << endl;
    int ans;
    if(i >= N && j >= M){
        ans = 0;
    }else if(i < N && j >= M){
        ans = 1 + solve(i+1, j, k - A[i]);
    }else if(i >= N && j < M){
        ans = 1 + solve(i, j+1, k - B[j]);
    }else{
        ans = max(1 +solve(i+1, j, k - A[i]),1 +solve(i, j+1, k - B[j]));
        // cout << ans << endl;
    }
    m[i][j] = ans;
    return ans;

}



int main() {
    
    cin >> N >> M >> K;
    
    rep(i,N){
        cin >> A[i];
    }
    rep(i,M){
        cin >> B[i];
    }
    // int dp[max(N,M)][2];

    // dp[i+1][0] = max 

    
    cout << solve(0,0,K) << endl;
    return 0;
}