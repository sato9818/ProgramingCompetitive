#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  vector<string> s(h);
  rep(i,h){
    cin >> s[i];
  }
  int ans = 0;
  for(int i=x-1;i<h;i++){
    if(s[i][y-1] == '.'){
      ans++;
    }
    if(s[i][y-1] == '#'){
      break;
    }
  }
  for(int i=x-1;i>=0;i--){
    if(s[i][y-1] == '.'){
      ans++;
    }
    if(s[i][y-1] == '#'){
      break;
    }
  }
  for(int j=y-1;j<w;j++){
    if(s[x-1][j] == '.'){
      ans++;
    }
    if(s[x-1][j] == '#'){
      break;
    }
  }
  for(int j=y-1;j>=0;j--){
    if(s[x-1][j] == '.'){
      ans++;
    }
    if(s[x-1][j] == '#'){
      break;
    }
  }
  if(s[x-1][y-1] == '.'){
    ans -= 3;
  }
  cout << ans << endl;
  return 0;
}