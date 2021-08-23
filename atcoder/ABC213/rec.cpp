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
  vector<int> ansh, answ;
  

  rep(i,n){
    int a, b;
    cin >> a >> b;
    hei[i] = a;
    wid[i] = b;
  }

  vector<int> hvals=hei;
  vector<int> wvals=wid;

  sort(hvals.begin(),hvals.end());
  sort(wvals.begin(),wvals.end());
  auto hitr=unique(hvals.begin(),hvals.end());
  auto witr=unique(wvals.begin(),wvals.end());//重複した要素を消す
  //これだと消されたところが穴になる。
  //unique()の戻り値は消されたところの次のイテレータ
  hvals.erase(hitr,hvals.end());//穴を消してあげる
  wvals.erase(witr,wvals.end());
  for(auto aa:hei){
    int ret=lower_bound(hvals.begin(),hvals.end(),aa) - hvals.begin();
    ansh.push_back(ret);
  }

  for(auto aa:wid){
    int ret=lower_bound(wvals.begin(),wvals.end(),aa) - wvals.begin();
    answ.push_back(ret);
  }

  rep(i,n){
    cout << ansh[i] + 1 << " " << answ[i] + 1 << endl;
  }


  return 0;
}
