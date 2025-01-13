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
    int n,d;
    cin >> n >> d;

    vector<string> strs(n);
    rep(i,n){
        cin >> strs[i];
    }
    int mx = 0;
    int cur = 0;
    rep(i,d) {
        int flag = 0;
        rep(j,n){
            if(strs[j][i] == 'x') {
                flag = 1;
                break;
            }
        }
        if(flag) {
            mx = max(mx, cur);
            cur = 0;
        } else {
            cur++;
        }
    }

    cout << max(mx, cur) << endl;

    return 0;
}
