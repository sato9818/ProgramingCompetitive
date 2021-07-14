#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  string n;
  cin >> n;
  
  if(n.size() % 2 == 0){
    string half = n.substr(0,n.size()/2);
    if(half + half <= n){
      cout << half << endl;
      return 0;
    }else{
      cout << stoi(half) - 1 << endl;
      return 0;
    }
  }else{
    string ans = "";
    if(n.size()/2 == 0){
      cout << 0 << endl;
      return 0;
    }
    rep(i, n.size()/2){
      ans += "9";
    }
    cout << ans << endl;
    return 0;
  }



  
  return 0;
}