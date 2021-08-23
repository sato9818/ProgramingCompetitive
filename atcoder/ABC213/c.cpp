#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> hei(n), wid(n);
  map<int, ll> cnth, cntw;
  vector<P> card(n);
  

  rep(i,n){
    int a, b;
    cin >> a >> b;
    card[i] = P(a,b);
    hei[i] = a;
    wid[i] = b;
  }

  sort(hei.begin(), hei.end());
  sort(wid.begin(), wid.end());

  int rec = 0;
  rep(i,n){
    if(cnth[hei[i]] != 0) continue;
    if(hei[i] == 1){
      cnth[hei[i]] = 0;
    }else{
      cnth[hei[i]] = cnth[rec] + hei[i] - rec - 1;
    }
    rec = hei[i];
  }

  rec = 0;

  rep(i,n){
    if(cntw[wid[i]] != 0) continue;
    if(wid[i] == 1){
      cntw[wid[i]] = 0;
    }else{
      cntw[wid[i]] = cntw[rec] + wid[i] - rec - 1;
    }
    rec = wid[i];
  }

  rep(i,n){
    cout << card[i].first - cnth[card[i].first] << " " << card[i].second - cntw[card[i].second] << endl;
  }


  return 0;
}
