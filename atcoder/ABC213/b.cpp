#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<P> a(n);

  rep(i,n){
    int s;
    cin >> s;
    a[i] = P(s,i);
  }

  sort(a.begin(), a.end());

  cout << a[n-2].second + 1 << endl;
  
  return 0;
}
