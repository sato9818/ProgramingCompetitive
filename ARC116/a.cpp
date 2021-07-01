#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int t;
  cin >> t;

  rep(i,t){
    ll c;
    cin >> c;
    if(c % 2 == 1){
      cout << "Odd" << endl;
    }else{
      if(c % 4 == 0){
        cout << "Even" << endl;
      }else if(c % 2 == 0){
        cout << "Same" << endl;
      }
    }
  }
  
  
  
  return 0;
}