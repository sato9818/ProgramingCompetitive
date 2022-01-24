#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

int main() {
  int h,w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  vector<vector<int>> visited(h, vector<int>(w,INF));

  rep(i,h){
    rep(j,w){
      cin >> s[i][j];
    }
  }
  
  deque<P> q;
  visited[0][0] = 0;
  q.emplace_back(0,0);
  int xs[4] = {0,1,0,-1};
  int ys[4] = {1,0,-1,0};
  while(!q.empty()){
    P p = q.front();
    q.pop_front();
    int x = p.first;
    int y = p.second;
    rep(i,4){
      int nx = x + xs[i];
      int ny = y + ys[i];
      if(nx >= 0 && nx < h && ny >= 0 && ny < w){
        if(s[nx][ny] == '.'){
          if(visited[nx][ny] > visited[x][y]){
            q.emplace_front(nx,ny);
            visited[nx][ny] = visited[x][y];
          }
        }
      }
    }
    for(int i=-2;i<3;i++){
      for(int j=-2;j<3;j++){
        if(abs(i) + abs(j) > 3 || abs(i) + abs(j) == 0){
          continue;
        }
        int nx = x + i;
        int ny = y + j;
        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
          if(visited[nx][ny] > visited[x][y] + 1){
            q.emplace_back(nx,ny);
            visited[nx][ny] = visited[x][y] + 1;
          }
        }
      }
    }
  }
  cout << visited[h-1][w-1] << endl;

  return 0;
}
