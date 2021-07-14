#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<P> item(n);
  vector<int> x(m);
  rep(i,n){
    int w,v;
    cin >> w >> v;
    item[i].second = w;
    item[i].first = v;
  }
  rep(i,m){
    cin >> x[i];
  }
  // sort(item.begin(), item.end(), my_compare);
  sort(item.begin(), item.end(), [](P a, P b){
   return a.first>b.first || (a.first ==b.first && a.second<b.second);
  });

  // for(int i=0; i<item.size(); i++){
  //   cout << item[i].first << ' ' << item[i].second << endl;
  // }

  rep(i,q){
    int l, r;
    cin >> l >> r;
    vector<int> box(m);
    box = x;
    for(int k=l-1;k<r;k++){
      box[k] = 0;
    }
    ll sum = 0;
    sort(box.begin(),box.end());
    rep(j,n){
      int value = item[j].first;
      int weight = item[j].second;
      rep(k,m){
        if(box[k] >= weight){
          box[k] = 0;
          sum += value;
          break;
        }
      }
    }
    cout << sum << endl;
  }  
  // 
  
  return 0;
}