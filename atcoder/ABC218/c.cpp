#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n),t(n);
  vector<P> ss,ts; 
  rep(i,n){
    cin >> s[i];
  }
  rep(i,n){
    cin >> t[i];
  }
  rep(i,n){
    rep(j,n){
      if(s[i][j] == '#'){
        ss.push_back(P(i,j));
      }
    }
  }
  rep(i,n){
    rep(j,n){
      if(t[i][j] == '#'){
        ts.push_back(P(i,j));
      }
    }
  }
  if(ss.size() != ts.size()){
    cout << "No" << endl;
    return 0;
  }
  rep(i,4){
    int flag = 0;
    sort(ss.begin(),ss.end());
    int difx = ts[0].first - ss[0].first;
    int dify = ts[0].second - ss[0].second;
    rep(j,ss.size()){
      int x = ss[j].first + difx;
      int y = ss[j].second + dify;
      if(x != ts[j].first || y != ts[j].second){
        flag = 1;
        break;
      }
    }
    
    if(flag == 0){
      cout << "Yes" << endl;
      return 0;
    }
    rep(j,ss.size()){
      int x = ss[j].first;
      int y = ss[j].second;
      ss[j].first = y;
      ss[j].second = n-1-x;
    }
  }
  
  cout << "No" << endl;
  
  return 0;
}
