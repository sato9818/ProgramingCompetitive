#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  x--;
  y--;
  vector< vector<P> > p(n);
  vector<P> pairs(m);
  
  rep(i,m){
    int a, b;
    ll t, k;
    cin >> a >> b >> t >> k;
    a--;
    b--;
    p[a].push_back(make_pair(b,i));
    p[b].push_back(make_pair(a,i));
    pairs[i] = make_pair(t,k);
  }
  const ll INF = 1001001001001001001;
  vector<ll> tm(n,INF);
  queue<ll> q;
  tm[x] = 0;
  for(auto v : p[x]){
    int dist = v.first;
    if(tm[dist] > pairs[v.second].first){
      q.push(dist);
      tm[dist] = pairs[v.second].first;
    }
  }
  while(!q.empty()){
    int pos = q.front(); q.pop();
    for(auto v : p[pos]){
      int dist = v.first;
      ll tx = pairs[v.second].first;
      ll kx = pairs[v.second].second;
      ll now = tm[pos];
      if(now % kx != 0){
        now += kx - now % kx;
      }
      if(tm[dist] > now + tx){
        tm[dist] = now + tx;
        q.push(dist);
      }
    }
  }
  
  if(tm[y] == INF){
    cout << -1 << endl;
  }else{
    cout << tm[y] << endl;
  }
  
  return 0;
}