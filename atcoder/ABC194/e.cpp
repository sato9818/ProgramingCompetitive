#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  int ans;

  map<int,int> mp;
  rep(i,m){
    mp[a[i]]++;
  }
  // cout << mp.size() << endl;
  rep(i,mp.size()){
    // cout << mp[i] << endl;
    if(mp[i] == 0){
      ans = i;
      break;
    }
    ans = i+1;
  }
  rep(i,n-m){
    mp[a[m+i]]++;
    mp[a[i]]--;
    if(mp[a[i]] == 0){
      ans = min(ans,a[i]);
    }
  }

  cout << ans << endl;
  
  return 0;
}