#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int a,b;
  cin >> a >> b;

  int mn = 1, mx = 6;
  mn *= a;
  mx *= a;

  if(mn <= b && b <= mx){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  

  return 0;
}