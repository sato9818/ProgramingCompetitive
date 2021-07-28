#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// 深さ優先で経路復元してる
void rec(const vector<vector<ll> > &dp, const vector<int> &a, int i, int j, deque<int> &keiro, vector<deque<int>> &ans) {
    if(ans.size() > 2){
      return;
    }
    if (i == 0) {
        if (j == 0) {
            ans.push_back(keiro);
        }
        return;
    }
 
    // 上へ遡る (dp[i-1][j] == 0) だったら無視)
    if (dp[i-1][j]) {
        rec(dp, a, i-1, j, keiro, ans);
    }
    // 左上へ遡る (dp[i-1][pre] == 0 だったら無視)
    int pre = (j+200-a[i-1]) % 200;
    if (dp[i-1][pre]) {
        keiro.push_front(i);
        rec(dp, a, i-1, pre, keiro, ans);
        keiro.pop_front();
    }
}
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
 
  rep(i,n){
    cin >> a[i];
    a[i] %= 200;
  }
 
  vector< vector<ll> > dp = vector(n+1, vector<ll>(200, 0));
 
  dp[0][0] = 1;
 
  rep(i,n){
    rep(j,200){
      dp[i+1][j] += dp[i][j];
      if(dp[i+1][j] > 3){
        dp[i+1][j] = 3;
      }
      dp[i+1][(j+a[i]) % 200] += dp[i][j];
      if(dp[i+1][(j+a[i]) % 200] > 3){
        dp[i+1][(j+a[i]) % 200] = 3;
      }
    }
  }
 
  deque<int> keiro;
  vector<deque<int>> ans;  
 
  rep(i,200){
    if(i == 0){
      if(dp[n][i] > 2){
        cout << "Yes" << endl;
        rec(dp, a, n, i, keiro, ans);
        for (int i = 1; i < 3; ++i) {
          cout << ans[i].size();
          for (auto el : ans[i]) cout << " " << el;
          cout << endl;
        }
        return 0;
      }
    }else if(dp[n][i] > 1){
      cout << "Yes" << endl;
      rec(dp, a, n, i, keiro, ans);
      for (int i = 0; i < 2; ++i) {
        cout << ans[i].size();
        for (auto el : ans[i]) cout << " " << el;
        cout << endl;
      }
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
