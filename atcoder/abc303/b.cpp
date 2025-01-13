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
    int n,m; 
    cin >> n >> m;
    vector<vector<int>> friends(n, vector<int>(n, 0));
    rep(i,m) {
        int prev;
        cin >> prev;
        rep1(j,n) {
            int now;
            cin >> now;
            friends[prev-1][now-1] = 1;
            friends[now-1][prev-1] = 1;
            prev = now;
        }
    }

    int ans = 0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(friends[i][j] == 0) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
