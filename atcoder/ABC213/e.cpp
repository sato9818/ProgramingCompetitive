#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1e9;
int h, w;
int visited[505][505] = {-1};

vector<vector<char> > punch(vector<vector<char> > s, int x, int y){
  int m[2] = {0, 1};
  rep(i,2){
    rep(j,2){
      if(x+m[i] >= 0 && x+m[i] < h && y+m[j] >= 0 && y+m[j] < w){
        s[x+m[i]][y+m[j]] = '.';
      }
    }
  }
  return s;
}

int ans = INF;

void dfs(vector<vector<char> > s, int x, int y, int sum){
  
  if(x == h-1 && y == w-1){
    ans = min(ans, sum);
    return;
  }
  if(!(x >= 0 && x < h && y >= 0 && y < w)){
    // cout << x << ": " << y << " visited " << visited[x][y]<< endl;
    return;
  }
  // cout << x << ": " << y << " visited " << visited[x][y]<< endl;
  if(visited[x][y] != -1){
    if(sum >= visited[x][y]){
      return;
    }
  }

  vector<vector<char>> ns;
  
  if(s[x][y] == '#'){
    visited[x][y] = sum+1;
    vector<int> m = {0,1};
    rep(i,2){
      rep(j,2){
        ns = punch(s, x-m[i], y-m[j]);
        dfs(ns, x+1, y, sum+1);
        dfs(ns, x, y+1, sum+1);
        dfs(ns, x-1, y, sum+1);
        dfs(ns, x, y-1, sum+1);
      }
    }
  }else{
    visited[x][y] = sum;
    dfs(s, x+1, y, sum);
    dfs(s, x, y+1, sum);
    dfs(s, x-1, y, sum);
    dfs(s, x, y-1, sum);
  }
}




int main() {
  cin >> h >> w;
  vector<vector<char> > s(h, vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
      visited[i][j] = -1;
    }
  }

  dfs(s, 0, 0, 0);

  // priority_queue<P, vector<P>, greater<P> > q;

  cout << ans << endl;
  return 0;
}


