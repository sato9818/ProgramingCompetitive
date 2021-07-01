#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  string x;
  cin >> x;
  string ans = "";
  rep(i,x.size()){
    if(x[i] == '.'){
      ans = x.substr(0,i);
      break;
    }
    if(i == x.size() - 1){
      ans = x.substr(0,i+1);
      break;
    }
    
  }
  cout << ans << endl;
  return 0;
}