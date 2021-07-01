#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int h,w;
bool used[16][16];

ll dfs(int i, int j, int a, int b){
  if(j >= w) {
    j = 0;
    i++;
  }
  // cout << i << " " << j << endl;
  if(a < 0 || b < 0) return 0;
  if(i == h) return 1;
  ll cnt = 0;
  if(used[i][j]) return dfs(i,j+1,a,b);
  used[i][j] = true;
  cnt += dfs(i, j+1, a, b-1);
  if(j+1 < w && !used[i][j+1]){
    used[i][j+1] = true;
    cnt += dfs(i, j+1, a-1, b);
    used[i][j+1] = false;
  }
  if(i+1 < h && !used[i+1][j]){
    used[i+1][j] = true;
    cnt += dfs(i, j+1, a-1, b);
    used[i+1][j] = false;
  }
  used[i][j] = false;
  return cnt;
}

int main() {
  int a, b;
  cin >> h >> w >> a >> b;

  ll ans = dfs(0, 0, a, b);

  cout << ans << endl;
  return 0;
}