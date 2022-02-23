#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<vector<P>> es(n);
    int mx = 0;
    rep(i,m) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        int cost = h[u] - h[v];
        if(cost < 0){
            es[u].emplace_back(v,-cost);
            es[v].emplace_back(u,0);
        }else{
            es[u].emplace_back(v,0);
            es[v].emplace_back(u,cost);
        }
        
    }

    priority_queue<P,vector<P>, greater<P>> pq;
    pq.push(P(0,0));
    vector<ll> dis(n, LINF);
    dis[0] = 0;

    while(!pq.empty()){
        P p = pq.top(); pq.pop();
        int v = p.second;
        ll d = p.first;
        if(dis[v] < d){
            continue;
        }
        for(auto e :es[v]){
            int nv = e.first;
            if(dis[nv] <= d + e.second){
                continue;
            }
            dis[nv] = d + e.second;
            pq.push(P(d+e.second, nv));
        }
    }

    ll ans = -LINF;
    rep(i,n){
        ans = max(ans, h[0] - h[i] - dis[i]);
    }
    cout << ans << endl;
    
    return 0;
}
