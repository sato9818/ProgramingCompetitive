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
    int n, d;
    cin >> n >> d;
    vector<P> p(n);
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        p[i] = P(x, y);
    }

    vector<vector<int>> dist(n, vector<int>(n, 0));

    rep(i,n)rep(j,n){
        dist[i][j] = (p[i].first - p[j].first)*(p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
    }

    vector<int> v(n,0);
    v[0] = 1;
    d = d*d;
    queue<int> q;
    q.push(0);
    while(q.size()) {
        int now = q.front();
        q.pop();
        rep(i,n) {
            if(dist[now][i] <= d && v[i] == 0) {
                v[i] = 1;
                q.push(i);
            }
        }
    }

    rep(i,n) {
        if(v[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}
