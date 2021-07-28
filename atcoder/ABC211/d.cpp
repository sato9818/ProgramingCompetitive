#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int INF = 1001001001;
const int MOD = 1000000007;

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int> > road(n);

  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    road[a].push_back(b);
    road[b].push_back(a);
  }

  queue<int> q;
  q.push(0);
  vector<int> cost(n,INF);
  vector<ll> cnt(n,0);
  cost[0] = 0;
  cnt[0] = 1;
  while(!q.empty()){
    int now = q.front(); q.pop();
    for(auto r : road[now]){
      if(cost[r] > cost[now] + 1){
        cost[r] = cost[now] + 1;
        cnt[r] = (cnt[r] + cnt[now]) % MOD;
        q.push(r);
      }else if(cost[r] == cost[now] + 1){
        cost[r] = cost[now] + 1;
        cnt[r] = (cnt[r] + cnt[now]) % MOD;
      }
    }
  }
  cout << cnt[n-1] << endl;
  return 0;
}
