#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
 
  if((c*d - b) <= 0){
    cout << -1 << endl;
  }else{
    cout << ceil((double)a/(c*d - b)) << endl;
  }
  
  
  return 0;
}