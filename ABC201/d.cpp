#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> str(h);
  
  rep(i,h){
    cin >> str[i];
  }
  vector<int> dp(w);
  dp[w-1] = 0;
  rep(i,h){
    vector<int> dp_buf(w);
    rep(j,w){
      if(i == 0 && j == 0){
        dp_buf[w-j-1] = 0;
      }else if(i == 0){
        if(((w-j-1) + (h-i-1)) % 2 == 0){
          if(str[h-i-1][w-j] == '+'){
            dp_buf[w-j-1] = dp_buf[w-j] + 1;
          }else{
            dp_buf[w-j-1] = dp_buf[w-j] - 1;
          }
        }else{
          if(str[h-i-1][w-j] == '+'){
            dp_buf[w-j-1] = dp_buf[w-j] - 1;
          }else{
            dp_buf[w-j-1] = dp_buf[w-j] + 1;
          }
        }
      }else if(j == 0){
        if(((w-j-1) + (h-i-1)) % 2 == 0){
          if(str[h-i][w-j-1] == '+'){
            dp_buf[w-j-1] = dp[w-j-1] + 1;
          }else{
            dp_buf[w-j-1] = dp[w-j-1] - 1;
          }
        }else{
          if(str[h-i][w-j-1] == '+'){
            dp_buf[w-j-1] = dp[w-j-1] - 1;
          }else{
            dp_buf[w-j-1] = dp[w-j-1] + 1;
          }
        }
      }else{
        if(((w-j-1) + (h-i-1)) % 2 == 0){
          int buf;
          if(str[h-i][w-j-1] == '+'){
            buf = dp[w-j-1] + 1;
          }else{
            buf = dp[w-j-1] - 1;
          }

          if(str[h-i-1][w-j] == '+'){
            dp_buf[w-j-1] = dp_buf[w-j] + 1;
          }else{
            dp_buf[w-j-1] = dp_buf[w-j] - 1;
          }
          dp_buf[w-j-1] = max(buf, dp_buf[w-j-1]);
        }else{
          int buf;

          if(str[h-i][w-j-1] == '+'){
            buf = dp[w-j-1] - 1;
          }else{
            buf = dp[w-j-1] + 1;
          }
          if(str[h-i-1][w-j] == '+'){
            dp_buf[w-j-1] = dp_buf[w-j] - 1;
          }else{
            dp_buf[w-j-1] = dp_buf[w-j] + 1;
          }
          dp_buf[w-j-1] = min(buf, dp_buf[w-j-1]);
        }
      }
    }
    swap(dp, dp_buf);
  }

  if(dp[0] > 0){
    cout << "Takahashi" << endl;
  }else if(dp[0] < 0){
    cout << "Aoki" << endl;
  }else{
    cout << "Draw" << endl;
  }

  return 0;
}