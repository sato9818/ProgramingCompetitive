#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,m;
  cin >> n >> m;
  vector<string> s(n);
  ll even = 0;
  rep(i,n){
    cin >> s[i];
    int cnt = 0;
    rep(j,s[i].size()){
      if(s[i][j] == '1'){
        cnt++;
      }
    }
    if(cnt % 2 == 0){
      even++;
    }
  }
  
  cout << even * (n - even) << endl;
  return 0;
}