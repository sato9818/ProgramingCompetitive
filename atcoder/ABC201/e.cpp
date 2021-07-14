#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector< vector<P> > t(500005);
const int MOD = 1000000007;
ll ans = 0;
int start;

void dfs(int v, ll sum, int anc){
  if(v > start){
    ans = (ans + sum) % MOD;
  }
  for(auto n : t[v]){
    if(n.first != anc){
      sum ^= n.second;
      dfs(n.first, sum, v);
      sum ^= n.second;
    }
    
  }
}

int main() {
  int n;
  cin >> n;

  rep(i,n-1){
    int a,b;
    ll w;
    cin >> a >> b >> w;
    a--;
    b--;
    t[a].push_back(make_pair(b, w));
    t[b].push_back(make_pair(a, w));
  }
  rep(i,n){
    start = i;
    dfs(i, 0, i);
  }
  

  cout << ans << endl;
  return 0;
}