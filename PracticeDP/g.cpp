#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// int dp[3001][3001];

int main() {
  int n, m;
  cin >> n >> m;

  vector< vector<int> > g(n);
  rep(i,m){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x].push_back(y);
  }
  vector<int> dp(n, -1);
  function<int(int)> dfs = [&](int v){
    if(dp[v] != -1) return dp[v];
    int ans = 0;
    for(auto node : g[v]){
      ans = max(ans, dfs(node)+1);
    }
    return dp[v] = ans;
  };
  int ans = 0;
  rep(i,n){
    ans = max(ans, dfs(i));
  }
  cout << ans << endl;
  return 0;
}