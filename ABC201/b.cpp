#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  vector<int> t(n);
  rep(i,n){
    cin >> s[i] >> t[i];
  }
  int mx = 0;
  rep(i,n){
    mx = max(t[i], mx);
  }
  int mx2 = 0;
  string name;
  rep(i,n){
    if(t[i] == mx){
      continue;
    }
    if(t[i] > mx2){
      mx2 = t[i];
      name = s[i];
    }
  }
  cout << name << endl;
  
  return 0;
}