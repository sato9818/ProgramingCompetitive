#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;

  vector<P> p(n);

  rep(i,n){
    int x,y;
    cin >> x >> y;
    p[i] = P(x,y);
  }

  sort(p.begin(),p.end());

  int pre = -1;

  map<int,int> m;
  ll ans = 0;

  rep(i,n){
    int x = p[i].first;
    int y = p[i].second;
    if(pre == x){
      m[y]++;
      pre = x;
      continue;
    }
    pre = x;

    int pre2 = x;
    int cnt = 0;
    for(int j=i;j<n;j++){
      int x2 = p[j].first;
      int y2 = p[j].second;

      if(pre2 != x2){
        ans += cnt * (cnt - 1) / 2;
        cnt = 0;
      }

      pre2 = x2;
      
      if(m[y2] > 0){
        cnt++;
      }
    }
    ans += cnt * (cnt - 1) / 2;
    m.clear();
    m[y]++;
  }

  cout << ans << endl;

  
  return 0;
}
