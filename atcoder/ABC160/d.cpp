#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int INF = 1001001001;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<vector<int> > node(n);

  rep(i,n-1){
    node[i].push_back(i+1);
    node[i+1].push_back(i);
  }
  x--;
  y--;
  node[x].push_back(y);
  node[y].push_back(x);

  vector<int> ans(n,0);

  rep(i,n-1){
    queue<int> q;
    q.push(i);
    vector<int> cost(n,INF);
    cost[i] = 0;
    while(!q.empty()){
      int now = q.front(); q.pop();
      for(auto v: node[now]){
        if(cost[v] > cost[now] + 1){
          cost[v] = cost[now] + 1;
          q.push(v);
        }
      }
    }
    for(int j = i+1;j<n;j++){
      if (cost[j] == INF) continue;
      ans[cost[j]]++;
    }
  }
  rep1(i,n){
    cout << ans[i] << endl; 
  }
  return 0;
}
