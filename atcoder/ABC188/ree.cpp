#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int INF = 1001001001;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> cur(n);
  vector<int> mns(n,INF);
  vector< vector<int> > e(n);
  
  rep(i,n) cin >> cur[i];

  rep(i,m){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    e[x].push_back(y);
  }

  rep(i,n){
    for(auto v: e[i]){
      mns[v] = min(mns[i], min(cur[i], mns[v]));
    }
  }
  int ans = -INF;

  rep(i,n){
    if(mns[i] == INF) continue;
    ans = max(ans, cur[i] - mns[i]);
  }

  cout << ans << endl;
  return 0;
}
