#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > e(n);

  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  vector<ll> ans(n);
  vector<int> child(n,1);

  function<void(int, int, int)> dfs = [&](int v, int p, int sum){
    ans[0] += sum;
    sum++;
    // cout << v << endl;
    for(auto next : e[v]){
      if(next != p){
        dfs(next, v, sum);
        child[v] += child[next];
      }
    }
    sum--;
    return;
  };

  function<void(int, int)> dfs2 = [&](int v, int p){
    for(auto next : e[v]){
      if(next != p){
        ans[next] = ans[v] - 2 * child[next] + child[0];
        dfs2(next, v);
      }
    }
    return;
  };

  dfs(0, -1, 0);
  dfs2(0,-1);
  rep(i,n) cout << ans[i] << endl;

  // rep(i,n){
  //   cout << child[i] << endl;
  // }
  
  return 0;
}
