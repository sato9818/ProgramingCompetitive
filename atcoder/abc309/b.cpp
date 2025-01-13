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
    vector<string> strs(n);

    rep(i,n) {
        cin >> strs[i];
    }
    string s1 = "", s2= "", s3 = "", s4= "";
    rep(i,n) {
        s1 += strs[0][i];
        s2 += strs[i][n-1];
        s3 += strs[n-1][i];
        s4 += strs[i][0];
    }

    strs[0] = s4[1] + s1.substr(0,n-1);
    strs[n-1] = s3.substr(1,n-1) + s2[n-2];

    rep(i,n-1) {
        strs[i][0] = s4[i+1];
        strs[i+1][n-1] = s2[i];
    }

    rep(i,n) {
        cout << strs[i] << endl;
    }

    return 0;
}
