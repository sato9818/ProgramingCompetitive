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
    string s;
    ll n;
    cin >> s >> n;

    ll sum = 0;

    rep(i,s.size()){
        char ch = s[i];
        if(ch == '1') {
            sum += (ll)1 << (s.size() - i - 1);
        }
    }

    if(sum > n) {
        cout << -1 << endl;
        return 0;
    }

    rep(i,s.size()) {
        char ch = s[i];
        if(ch == '?') {
            ll num = (ll)1 << (s.size() - i - 1);
            sum += num;
            if(sum > n) {
                sum -= num;
            }
        }
    }
    cout << sum << endl;

    return 0;
}
