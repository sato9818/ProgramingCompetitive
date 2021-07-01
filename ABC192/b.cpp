#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  rep(i,s.length()){
    char c = s[i];
    if(i % 2 == 0 && isupper(c)){
      cout << "No" << endl;
      return 0;
    }
    if(i % 2 == 1 && islower(c)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}