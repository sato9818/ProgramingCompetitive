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

    b[m] = c[m+n] / a[n]; 
    // b[3] = c[3+1] / a[1];
    for(int i=m+n-1;i>=n;i--){
        int sum = 0;
        for(int j=min(m, i);j>i-n;j--){
            // cout << "i:j = " << i << ":" << j << endl;
            // cout << a[i-j] << " " << b[j] << endl;
            sum += a[i-j] * b[j]; 
        }
        
        b[i-n] = (c[i] - sum) / a[n];
        // if(i-n == 0){
        //     cout << c[i] << " " << sum << " " << a[n] << endl;
        // }
    }

    rep(i,m+1){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
