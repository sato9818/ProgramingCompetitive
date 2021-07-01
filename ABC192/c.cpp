#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  string n;
  cin >> n >> k;
  
  rep(i,k){
    sort(n.begin(), n.end());
    int mn = stoi(n);
    sort(n.begin(), n.end(), greater<int>());
    int mx = stoi(n);
    n = to_string(mx - mn);
  }

  cout << n << endl;
  return 0;
}