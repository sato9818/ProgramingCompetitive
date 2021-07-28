#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PP = pair<pair<int, int>, int>;

int main() {
  int n;
  cin >> n;

  vector<PP> house(n);
  vector<PP> cand;

  rep(i,n){
    int x,y;
    cin >> x >> y;
    house[i] = make_pair(make_pair(x,y), i);
  }

  sort(house.begin(), house.end());

  cand.push_back(house[0]);
  cand.push_back(house[1]);
  cand.push_back(house[n-2]);
  cand.push_back(house[n-1]);

  sort(house.begin(), house.end(), [](PP a, PP b){
   return a.first.second < b.first.second;
  });

  auto push = [&](PP h) { 
    rep(i,cand.size()){
      if(cand[i].second == h.second){
        return;
      }
    }
    cand.push_back(h);
  };
  push(house[0]);
  push(house[1]);
  push(house[n-2]);
  push(house[n-1]);
  
  vector<int> ans;
  rep(i,cand.size()){
    for(int j = i+1;j<cand.size();j++){
      ans.push_back(max(abs(cand[i].first.first - cand[j].first.first), abs(cand[i].first.second - cand[j].first.second)));
    }
  }

  sort(ans.rbegin(), ans.rend());

  cout << ans[1] << endl;


  return 0;
}
