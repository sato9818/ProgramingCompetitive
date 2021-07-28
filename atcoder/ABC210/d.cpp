#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const ll INF = 1001001001001001001;

int main() {
  int h,w,c;
  cin >> h >> w >> c; 
  vector<vector<int> > a(h);
  

  rep(i,h){
    rep(j,w){
      int cost;
      cin >> cost;
      a[i].push_back(cost);
    }
  }

  

  ll ans = INF;
  rep(k,2){
    vector<vector<ll> > mn(h, vector<ll>(w, INF));
    rep(i,h){
      if(k == 1){
        reverse(a[i].begin(),a[i].end());
      }
      rep(j,w){
        mn[i][j] = min(mn[i][j], (ll)a[i][j] - (ll)c * (i + j + 2) );
      }
    }
    rep(i,h){
      rep(j,w){
        if(i != 0 && j != 0){
          ll cmn = min(mn[i-1][j], mn[i][j-1]);
          ans = min(ans, (ll)a[i][j] + (ll)c * (i+j+2) + cmn);
          mn[i][j] = min(mn[i][j], cmn);
        }else if(i == 0 && j != 0){
          ans = min(ans, (ll)a[i][j] + (ll)c * (i+j+2) + mn[i][j-1]);
          mn[i][j] = min(mn[i][j], mn[i][j-1]);
        }else if(i != 0 && j == 0){
          ans = min(ans, (ll)a[i][j] + (ll)c * (i+j+2) + mn[i-1][j]);
          mn[i][j] = min(mn[i][j], mn[i-1][j]);
        }
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
