#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

struct Edge {
  int to, t, k;
  Edge(int to, int t, int k): to(to), t(t), k(k) {}
}; 

int main() {
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  x--;
  y--;
  vector<vector<Edge>> g(n);
  
  rep(i,m){
    int a, b, t, k;
    cin >> a >> b >> t >> k;
    --a;
    --b;
    g[a].emplace_back(b,t,k);
    g[b].emplace_back(a,t,k);
  }
  const ll INF = 1e18;
  vector<ll> dist(n,INF);
  priority_queue< P, vector<P>, greater<P>> q;
  auto push = [&](int v, ll x){
    if(dist[v] <= x) return;
    dist[v] = x;
    q.push(P(v,x));
  };
  push(x, 0);
  while(!q.empty()){
    P p = q.top(); q.pop();
    int pos = p.first;
    ll cost = p.second;
    if(dist[pos] < cost){
      continue;
    }
    for(Edge& e : g[pos]){
      ll nx = (x+e.k-1)/e.k*e.k + e.t;
      push(e.to, nx);
    }
  }
  ll ans = dist[y];
  if(ans == INF){
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}