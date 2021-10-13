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

  ll ans = 0;

  rep(i,n){
    int x1 = p[i].first;
    int y1 = p[i].second;


    rep(j,n){
      int x2 = p[j].first;
      int y2 = p[j].second;
      if(x1 < x2 && y1 < y2){
        if(binary_search(p.begin(), p.end(), P(x1,y2)) && binary_search(p.begin(), p.end(), P(x2,y1))){
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  
  return 0;
}
