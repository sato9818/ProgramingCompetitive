#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int c[505][505];

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  int mn = 1001001001, mni;
  rep(i,n){
    rep(j,n){
      cin >> c[i][j];
    }
    if(mn > c[i][0]){
      mn = c[i][0];
      mni = i;
    }
  }
  mn = 0;
  rep(i,n){
    int x = c[i][0] - c[mni][0];
    for(int k = 1;k<n;k++){
      int y = c[i][k] - c[mni][k];
      if(x != y){
        cout << "No" << endl;
        return 0;
      }
    }
    a[i] = x;
  }
  cout << "Yes" << endl;
  rep(i,n){
    cout << a[i] << " ";
  }
  cout << endl;
  rep(j,n){
    cout << c[mni][j] << " ";
  }
  cout << endl;
  return 0;
}