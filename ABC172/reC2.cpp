#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N+1),B(M+1);
    // vector<int>::iterator position;
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
    
    rep(i,N+1){
        sum += A[i];
        if(sum > K){
            break;
        }
        ll rest = K - sum;
        int j = 0;
        if(rest > 0){
            auto position = upper_bound(B.begin(), B.end(), rest);
            j = distance(B.begin(), position);
            j--;
        }
        
        ans = max(ans, i+j);
    }
    
    cout << ans << endl;
    return 0;
}