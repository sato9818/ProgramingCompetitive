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
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), c(n+m+1), b(m+1,0);
    rep(i,n+1) cin >> a[i];
    rep(i,m+n+1) cin >> c[i];

    b[0] = c[0] / a[0]; 
    rep1(i,n+m+1){
        int sum = 0;
        rep1(j,n+1){
            if(j <= i){
                sum += a[j] * b[i-j]; 
            }
        }
        b[i] = (c[i] - sum) / a[0];
    }

    rep(i,m+1){
        cout << b[i] << endl;
    }
    return 0;
}
