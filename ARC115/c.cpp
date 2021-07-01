#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  int mx = 1, th = 2;

  rep(i,n){
    if(i+1 == th){
      mx++;
      th *= 2;
    }
    cout << mx << " ";
  }
  cout << endl;
  return 0;
}