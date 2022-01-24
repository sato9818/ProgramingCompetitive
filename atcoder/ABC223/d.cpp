#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n, m;
  cin >> n >> m;
  
  vector< vector<int> > g(n);
  vector<int> cnt(n,0);

  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    cnt[b]++;
  }

  priority_queue<int, vector<int>, greater<int>> q;
  rep(i,n){
    if(cnt[i] == 0){
      q.push(i);
    }
  }
  vector<int> ans;

  while(!q.empty()){
    int v = q.top(); q.pop();
    ans.push_back(v);
    for(auto node : g[v]){
      cnt[node]--;
      if(cnt[node] == 0){
        q.push(node);
      }
    }
  }

  if(ans.size() == n){
    rep(i,n){
      cout << ans[i] + 1 << " ";
    }
    cout << endl;
  }else{
    cout << -1 << endl;
  }

  return 0;
}
