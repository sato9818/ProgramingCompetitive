#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<P>> path(n, vector<P>(n, P(LINF, 0LL)));

    rep(i,n) path[i][i] = P(0,0);

    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            if(s[j] == 'Y'){
                path[i][j] = P(1, a[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++){
                if(path[j][k].first > path[j][i].first + path[i][k].first){
                    path[j][k].first = path[j][i].first + path[i][k].first;
                    path[j][k].second = path[j][i].second + path[i][k].second;
                }else if(path[j][k].first == path[j][i].first + path[i][k].first){
                    path[j][k].second = max(path[j][k].second, path[j][i].second + path[i][k].second);
                }
            }

    int q;
    cin >> q;

    rep(i,q){
        int u,v;
        cin >> u >> v;
        u--;v--;
        if(path[u][v].first == LINF) cout << "Impossible" << endl;
        else cout << path[u][v].first << " " << path[u][v].second + a[u] << endl;
    }

    return 0;
}
