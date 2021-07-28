#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mx = 0;
  rep(i,n){
    cin >> a[i];
    mx = max(a[i], mx);
  }
  int mn = INF;
  int ans;
  rep(i,n){
    if(a[i] == mx){
      continue;
    }
    if(abs(a[i] * 2 - mx) < mn){
      ans = a[i];
      mn = abs(a[i] * 2 - mx);
    }
  }

  cout << mx << " " << ans << endl;
  return 0;
}
