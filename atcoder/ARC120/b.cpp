#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int h, w;
  cin >> h >> w; 
  vector<string> strs(h);
  rep(i,h){
    cin >> strs[i];
  }
  ll ans = 1;
  const int MOD = 998244353;
  
  for(int i=1;i<h;i++){
    for(int j=1;j<w;j++){
      if(strs[i-1][j] == '.' && strs[i][j-1] == '.'){
        ans = (ans*2) % MOD;
      }else if(strs[i-1][j] == '.' || strs[i][j-1] == '.' || strs[i-1][j] == strs[i][j-1]) {
        ans = ans;
      }else{
        ans = 0;
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}