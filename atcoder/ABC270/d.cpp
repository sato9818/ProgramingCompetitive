#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k){
        cin >> a[i];
    }

    vector<int> dp1(n+1,-1), dp2(n+1,-1);
    dp2[0] = 0;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<k;j++){
            if(dp2[i] != -1 && i + a[j] <= n)
                dp1[i+a[j]] = max(dp1[i+a[j]], i-dp2[i]+a[j]);
        }
        for(int j=0;j<k;j++){
            if(dp1[i] != -1 && i + a[j] <= n)
                dp2[i+a[j]] = max(dp2[i+a[j]], i-dp1[i]+a[j]);
        }
    }

    rep(i,n+1) cout << dp1[i] << endl;
    rep(i,n+1) cout << dp2[i] << endl;
    
    cout << dp1[n] << endl;
    return 0;
}
