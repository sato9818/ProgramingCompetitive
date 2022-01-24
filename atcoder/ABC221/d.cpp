#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<P> d;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    d.push_back(P(a, 1));
    d.push_back(P(a+b, -1));
  }

  sort(d.begin(), d.end());

  vector<int> ans(n+1,0);
  int cnt = 0;
  rep(i,d.size()-1){
    cnt += d[i].second;
    ans[cnt] += d[i+1].first - d[i].first;
  }
  rep1(i,n+1){
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
