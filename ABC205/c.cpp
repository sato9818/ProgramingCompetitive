#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans;

  if(abs(a) > abs(b)){
    ans = 1;
  }else if(abs(a) < abs(b)){
    ans = -1;
  }else{
    ans = 0;
  }

  if(a < 0 && b < 0){
    if(c % 2 == 1){
      ans *= -1;
    }
  }else if(a > 0 && b < 0){
    if(c % 2 == 1){
      ans = 1;
    }
  }else if(a < 0 && b > 0){
    if(c % 2 == 1){
      ans = -1;
    }
  }else if((a == 0 || b == 0) && (a < 0 || b < 0)){
    if(c % 2 == 1){
      ans *= -1;
    }
  }

  if(ans == 1){
    cout << ">" << endl;
  }else if(ans == -1){
    cout << "<" << endl;
  }else{
    cout << "=" << endl;
  }
  
  
  return 0;
}