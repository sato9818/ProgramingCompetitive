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
    int r, c;
    cin >> r >> c;
    vector<vector<char>> b(r, vector<char>(c));
    rep(i,r) rep(j,c) cin >> b[i][j];
    auto bomb = [&](int x, int y, int power) {
        rep(i,r) {
            rep(j,c) {
                if(b[i][j] == '#' && abs(x-i) + abs(y-j) <= power) b[i][j] = '.';
            }
        }
    };

    rep(i,r) rep(j,c) {
        if(b[i][j] != '.' && b[i][j] != '#') {
            bomb(i, j, b[i][j] - '0');
            b[i][j] = '.';
        }
    }

    rep(i,r) {
        rep(j,c) cout << b[i][j];
        cout << endl;
    }

    return 0;
}
