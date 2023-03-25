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
    rep(i,n){
        vector<ll> x(3);
        rep(j,3){
            cin >> x[j];
        }
        sort(x.begin(), x.end());
        if((x[0] + x[1] + x[2]) % 3 != 0){
            cout << -1 << endl;
            continue;
        } else if ((x[2]-x[0]) % 2 != 0 || (x[1]-x[0]) % 2 != 0) {
            cout << -1 << endl;
            continue;
        }

        ll sum = (x[0] + x[1] + x[2]) / 3;
        ll d = abs(sum - x[0]) + abs(sum - x[1]) + abs(sum - x[2]);
        cout << d/4 << endl;
    }
    return 0;
}