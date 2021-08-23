#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector<int> visited(200005,0);
vector<vector<int> > road(200005);

void dfs(int now, int pre){
  if(now != 0)cout << " " << now + 1;
  visited[now] = 1;
  sort(road[now].begin(), road[now].end());
  for(auto r : road[now]){
    if(!visited[r]){
      dfs(r, now);
      cout << " " << now + 1 ;
    }
  }
}

int main() {
  int n;
  cin >> n;

  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    road[a].push_back(b);
    road[b].push_back(a);
  }
  cout << 1;
  dfs(0, -1);
  cout << endl;

  return 0;
}
