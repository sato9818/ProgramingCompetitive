#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N+1),B(M+1);
    
    rep(i,N){
        cin >> A[i+1];
    }
    rep(i,M){
        cin >> B[i+1];
    }
    rep(i,M){
        B[i+1] += B[i];
    }

    int ans = 0;
    ll sum = 0;
    int j = M;
    rep(i,N+1){
        sum += A[i];
        if(sum > K){
            break;
        }
        while(true){
            if(sum + B[j] <= K){
                break;
            }
            if(j == 0){
                break;
            }
            j--;
        }
        ans = max(ans, i+j);
    }
    
    cout << ans << endl;
    return 0;
}