#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a,b;
  ll w;
  cin >> a >> b >> w;
  w *= 1000;
  int mn = -1,mx = -1;

  int rema = w % a;
  int diva = w / a;
  
  mx = diva;

  int remb = w % b;
  int divb = w / b;

  if(mx == divb && rema != 0 && remb !=0){
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }
  
  if(remb == 0){
    mn = divb;
  }else{
    mn = divb + 1;
  }
  cout << mn << " " << mx << endl;
  
  
  return 0;
}