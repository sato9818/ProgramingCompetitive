#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector< vector<P> > t(500005);
vector<ll> xors(500005);
vector<int> visited(500005);
const int MOD = 1000000007;

void dfs(int v, ll sum){
  xors[v] = sum;
  visited[v] = 1;
  for(auto n : t[v]){
    if(!visited[n.first]){
      sum ^= n.second;
      dfs(n.first, sum);
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
    t[a].push_back(P(b, w));
    t[b].push_back(P(a, w));
  }
  
  visited[0] = 1;
  dfs(0, 0);
  
  
  ll ans = 0;
  ll mul = 1;

  rep(i,60){
    ll cnt = 0;
    rep(j,n){
      int x = (xors[j] >> i) & 1;
      // cout << x << endl;
      if(x){
        cnt++;
      }
    }
    ans = (ans + mul * (cnt * (n-cnt) % MOD)) % MOD;
    mul = (mul * 2) % MOD;
  }
  
  cout << ans << endl;
  return 0;
}