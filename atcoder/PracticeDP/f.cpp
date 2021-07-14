#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dp[3001][3001];

int main() {
  string s, t;
  cin >> s;
  cin >> t;

  rep(i, s.size()+1) dp[i][0] = 0;
  rep(j, t.size()+1) dp[0][j] = 0;

  rep1(i,s.size()+1){
    rep1(j,t.size()+1){
      if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  int len = dp[s.size()][t.size()]; 
  int i = s.size();
  int j = t.size();
  string ans = "";
  while(len > 0){
    if(s[i-1] == t[j-1]){
      ans = s[i-1] + ans;
      i--;
      j--;
      len--;
    }else if(dp[i][j-1] > dp[i-1][j]){
      j--;
    }else{
      i--;
    }
  }
  cout << ans << endl;
  return 0;
}