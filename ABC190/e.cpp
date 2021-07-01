#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void chmin(int& x, int y){ x = min(x,y); }

int main() {
    int n,m;
    cin >> n >> m;
    vector< vector<int> > to(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int k;
    cin >> k;
    vector<int> c(k);
    rep(i,k){
        cin >> c[i];
        c[i]--;
    }
    //dist[i][j]：iからjまでの距離
    vector< vector<int> > dist(k, vector<int>(k));

    const int INF = 1001001001;

    //頂点svからのそれぞれの頂点への最短距離の配列を出してくれる
    //-std=c++11をオプションでつける
    auto bfs = [&](int sv){
        vector<int> dist(n, INF);
        queue<int> q;
        dist[sv] = 0;
        q.push(sv);
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int u : to[v]){
                if(dist[u] == INF){
                    dist[u] = dist[v]+1;
                    q.push(u);
                }
            }
        }
        return dist;
    };

    rep(i,k){
        vector<int> d = bfs(c[i]);
        rep(j,k){
            dist[i][j] = d[c[j]];
        }
    }
    //今までに訪れた頂点集合を表している。
    int k2 = 1<<k;
    vector< vector<int> > dp(k2, vector<int>(k,INF));
    //自分自身の頂点には1
    rep(i,k) dp[1<<i][i] = 1;

    rep(s,k2)rep(i,k){
        //少なくとも今いる頂点に訪れている必要がある。
        if(~s>>i&1) continue;
        rep(j,k){
            //訪れたところは再度訪れる必要はないのでskip。
            if(s>>j&1) continue;
            chmin(dp[s|1<<j][j], dp[s][i]+dist[i][j]);
        }
    }
    int ans = INF;
    rep(i,k) chmin(ans, dp[k2-1][i]);
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}