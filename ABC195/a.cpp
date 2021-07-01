#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int m,h;
  cin >> m >> h;
  
  if(h%m == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
  return 0;
}