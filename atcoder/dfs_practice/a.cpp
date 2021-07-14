#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int h,w;
char m[505][505];
bool passed[505][505];

bool dfs(int i, int j){
  // cout << i << " " << j << endl;
  bool ok = false;
  if(m[i][j] == '#' || passed[i][j]) return false;
  if(m[i][j] == 'g'){
    return true;
  }
  passed[i][j] = true;
  if(j+1 < w){
    ok |= dfs(i,j+1);
  }
  if(i+1 < h){
    ok |= dfs(i+1,j);
  }
  if(j-1 >= 0){
    ok |= dfs(i,j-1);
  }
  if(i-1 >= 0){
    ok |= dfs(i-1,j);
  }
  
  return ok;
}

int main() {
  int si, sj;
  cin >> h >> w;
  rep(i,h){
    rep(j,w){
      cin >> m[i][j];
      if(m[i][j] == 's'){
        si = i;
        sj = j;
      }
    }
  }
  bool ans = dfs(si, sj);
  // rep(i,h){
  //   rep(j,w){
  //     cout << m[i][j];
  //   }
  //   cout << endl;
  // }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  // cout << ans << endl;
  return 0;
}