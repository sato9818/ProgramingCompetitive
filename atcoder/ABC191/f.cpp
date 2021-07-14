#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N){
    cin >> a[i];
  }
  map<int,int> mp;
  int l = 1e9;
  auto add = [&](int a, int x){
    int p = mp[x];
    cout << p << endl;
    mp[x] = gcd(a,p);
  };
  rep(i,N){
    for(int j = 1;j*j<= a[i];j++){
      if(a[i] % j == 0){
        add(a[i],j);
        add(a[i],a[i]/j);
      } 
      l = min(l,a[i]);
    }
  }
  
  int ans = 0;
  for(auto [x,g] : mp){
    if(x <= l && g == x) ans++;
  }
  
  cout << ans << endl;

  return 0;
}