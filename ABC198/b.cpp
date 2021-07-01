#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  string n;
  cin >> n;
  rep(i,10){
    string str = n;
    reverse(str.begin(), str.end());
    if(n == str){
      cout << "Yes" << endl;
      return 0;
    }
    n = "0" + n;
  }
  
  cout << "No" << endl;
  return 0;
}