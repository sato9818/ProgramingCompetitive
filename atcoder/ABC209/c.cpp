#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 1000000007;

int main() {
  int n;

  cin >> n;

  vector<int> c(n);

  rep(i,n){
    cin >> c[i];
  }
  sort(c.begin(),c.end());
  ll sum = 1;

  rep(i,n){
    sum = (sum * (c[i] - i)) % MOD;
  }

  cout << sum << endl;

  
  
  return 0;
}