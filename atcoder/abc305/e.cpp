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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    priority_queue<P> q;
    rep(i,k){
        int p, h;
        cin >> p >> h;
        p--;
        q.push(P(h,p));
    }

    vector<int> visited(n,0);
    while(q.size()){
        P p = q.top(); q.pop();
        int h = p.first;
        int pos = p.second;
        if(visited[pos]) continue;
        visited[pos] = 1;
        if(h == 0) continue;
        for(auto next : v[pos]) {
            q.push(P(h-1, next));
        }
    }

    int cnt = 0;

    rep(i,n) {
        if(visited[i] == 1) {
            cnt++;
        }
    }

    cout << cnt << endl;

    rep(i,n) {
        if(visited[i] == 1) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
