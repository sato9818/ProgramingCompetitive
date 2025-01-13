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
    int n,h,x;
    cin >> n >> h >> x;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    rep(i,n) {
        if(h+p[i]>=x) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}
