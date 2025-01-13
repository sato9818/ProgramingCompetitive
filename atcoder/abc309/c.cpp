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
    int n, k;
    cin >> n >> k;
    ll sum = 0;

    vector<P> pills(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        sum += b;
        pills[i] = P(a,b);
    }

    sort(pills.begin(), pills.end());

    int ans = 1;
    rep(i,n) {
        if(sum <= k){
            cout << ans << endl;
            return 0;
        }
        sum -= pills[i].second;
        ans = pills[i].first + 1;
    }

    cout << ans << endl;

    return 0;
}
