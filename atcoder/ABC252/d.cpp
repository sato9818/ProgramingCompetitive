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
    int n;
    cin >> n;
    vector<int> a(n), uniques(n);
    rep(i,n) cin >> a[i];

    map<int,int> m;
    rep(i,n){
        m[a[i]]++;
    }

    ll sum = (ll)n * (n-1) * (n-2) / 6;
    for(auto [k,v] : m){
        if(v > 1){
            sum -= (ll)v * (v-1) * (v-2) / 6 + (ll)v * (v-1) / 2 * (n-v);
        }
    }
    
    cout << sum << endl;
    return 0;
}

// 被りの数 u
// それ以外 n - u
// u C 3 + u C 2 * (n-u)

