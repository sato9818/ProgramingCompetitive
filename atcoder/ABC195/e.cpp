#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s, x;
  cin >> n;
  cin >> s;
  cin >> x;

  vector<int> dp(7,0);
  //ゲームの勝敗から巻き戻って考える。
  dp[0] = 1;
  int mul = 1;
  for(int i = n-1;i>=0;i--){
    vector<int> newdp(7,0);
    rep(j,7){
      int rem = (j + mul * (s[i]-'0')) % 7;
      if(x[i] == 'T'){
        newdp[j] = dp[j] | dp[rem];
      }else{
        newdp[j] = dp[j] & dp[rem];
      }
    }
    mul = (mul*10) % 7;
    swap(newdp, dp);
  }
  //全通り考えた結果dp[0]が1でtakahashiくんの勝ち
  // rep(i,7){
  //   cout << dp[i] << endl;
  // }
  
  if(dp[0] == 1){
    cout << "Takahashi" << endl;
  }else{
    cout << "Aoki" << endl;
  }
  return 0;
}