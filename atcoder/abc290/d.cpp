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
    int t;
    cin >> t;
    rep(i,t) {
        int n, d, k;
        cin >> n >> d >> k;
        k--;
        d %= n;
        if(d == 0) {
            cout << k << endl;
            continue;
        }
        ll l = lcm((ll)n,(ll)d);

        // cout << l << endl;
        
        int loop = (ll)k * d / l;
        // int rem = k % div;
        // cout << g << " " << loop << " " << rem << endl;
        cout << (ll) k * d % n + loop << '\n';
    }
    


    return 0;
}
