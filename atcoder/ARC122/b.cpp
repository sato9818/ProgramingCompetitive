#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n; 
  vector<double> a(n);
  double asum = 0;
  rep(i,n){
    cin >> a[i];
    asum += a[i];
  }
  sort(a.begin(),a.end());

  ll remsum = 0;
  double ans = 1001001001;
  rep(i,n){
    double xsum = a[i] / 2 * n;
    double sum = a[i] * (n-i) + remsum;
    remsum += a[i];
    ans = min((xsum + asum - sum) / n, ans);
  }
  cout << fixed << setprecision(15) << ans << endl;
  // cout <<  << endl;
  
  return 0;
}