#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int ans = -2001001001;

vector<int> cur(500005);
vector<int> visited(500005);
vector< vector<int> > e(500005);
int start;
ll cnt = 0;

void dfs(int p, int mn){
  visited[p] = 1;
  if(p != start) ans = max(ans, cur[p] - mn);
  rep(i,2){
    cnt++;
  }
  
}

int main() {
  int n,m;
  cin >> n >> m;
  // rep(i,n) cin >> cur[i];

  // rep(i,m){
  //   int x, y;
  //   cin >> x >> y;
  //   x--;
  //   y--;
  //   e[x].push_back(y);
  // }

  rep(i,n){
    dfs(i, cur[i]);
    // if(!visited[i]){
    //   start = i;
      
    // }
  }
  

  cout << ans << endl;
  cout << cnt << endl;

  
  return 0;
}
