#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
ll dp[1010][1024][10] = {0};

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;

  
  map<char,int> cton;
  char c = 'A';
  rep(i,10){
    cton[c] = i;
    c++; 
  }

  rep(i,n){
    int ch = cton[s[i]];
    rep(j,1<<10){
      rep(k,10){
        dp[i+1][j][k] = dp[i][j][k];
      }
    }
    dp[i+1][1<<ch][ch]++;
    rep(j,1<<10){
      rep(k,10){
        if(((j >> ch) & 1) == 0){
          dp[i+1][j+(1<<ch)][ch] += dp[i][j][k];
          dp[i+1][j+(1<<ch)][ch] %= MOD;
        }else{
          if(k == ch){
            dp[i+1][j][ch] += dp[i][j][k];
            dp[i+1][j][ch] %= MOD;
          }
        }
      }
    }
  }

  ll ans = 0;
  rep(j,1<<10){
    rep(k,10){
      ans = (ans + dp[n][j][k]) % MOD;
    }
  }

  cout << ans << endl;
  
  return 0;
}
