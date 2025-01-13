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

    vector<vector<int>> e(n);
    rep(i,n-1){
        int p;
        cin >> p;
        p--;
        e[p].push_back(i+1);
    }

    vector<int> visited(n,0);
    priority_queue<P> q;

    rep(i,m) {
        int x,y;
        cin >> x >> y;
        x--;
        q.push(P(y,x));
    }

    while(q.size()) {
        P p = q.top(); q.pop();
        int d = p.first;
        int cur = p.second;
        if(visited[cur]) continue;
        visited[cur] = 1;
        if(d==0) continue;
        for(int next : e[cur]) {
            q.push(P(d-1, next));
        }
    }

    int ans = 0;

    rep(i,n) {
        if(visited[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}
