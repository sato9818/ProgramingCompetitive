#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int a,b;

  cin >> a >> b;
  if(b-a < 0){
    cout << 0 << endl;
  }else{
    cout << b-a + 1 << endl;
  }
  
  return 0;
}