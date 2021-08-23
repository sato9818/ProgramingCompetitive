#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n, m, k;

  vector< vector<int> > road(n);

  rep(i,m){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    road[u].push_back(v);
    road[v].push_back(u);
  }

  
  
  return 0;
}
