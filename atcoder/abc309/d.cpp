#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int bfs(int n, int start, vector<vector<int>>& e) {
    queue<P> q;
    vector<int> visited(n,0); 
    q.push(P(start,0));
    
    int ans = 0;
    while(q.size()){
        P p = q.front(); q.pop();
        int cur = p.first;
        int d = p.second;
        if(visited[cur]) continue;
        visited[cur] = 1;
        ans = max(ans, d);
        for(int next : e[cur]) {
            q.push(P(next, d+1));
        }
    }
    return ans;
}

int main() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;

    vector<vector<int>> e(n1+n2);

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    cout << bfs(n1+n2, 0, e) + bfs(n1+n2, n1+n2-1, e) +1 << endl;

    return 0;
}
