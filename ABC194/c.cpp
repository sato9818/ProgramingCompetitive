#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  ll squared_sum = 0, sum = 0;
  rep(i,n){
    squared_sum += a[i] * a[i];
    sum += a[i];
  }
  ll ans = n * squared_sum - sum * sum;

  cout << ans << endl;
  
  return 0;
}