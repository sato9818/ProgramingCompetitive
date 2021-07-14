#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector< vector<P> > road(n);
  rep(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    road[--a].push_back(make_pair(--b,c));
  }
  const int INF = 1001001001;
  // cout << road[0].size() << endl;
  rep(i, n){
    vector<int> dp(n,INF);
    queue<int> q;
    rep(j,road[i].size()){
      q.push(road[i][j].first);
      dp[road[i][j].first] = min(road[i][j].second, dp[road[i][j].first]);
    }
    while(!q.empty()){
      int place = q.front(); q.pop();
      rep(j,road[place].size()){
        int next = road[place][j].first;
        int cost = road[place][j].second;
        if(dp[place] + cost < dp[next] ){
          dp[next] = dp[place] + cost;
          q.push(next);
        }
      }
    }
    if(dp[i] == INF){
      cout << -1 << endl;
    }else{
      cout << dp[i] << endl;
    }
  }
  return 0;
}