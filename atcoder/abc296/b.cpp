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
    char ch1 = '8';
    string ans = "";
    rep(i,8) {
        string s;
        cin >> s;
        rep(j,8) {
            if(s[j] == '*') {
                ans += ('a'+j);
                ans += ch1;
            }
        }
        ch1--;
    }
    cout << ans << endl;

    return 0;
}
