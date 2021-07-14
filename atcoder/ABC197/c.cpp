#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll ans = 1001001001001001001;
  rep(i,1<<(n-1)){
    ll bxor = 0;
    ll bor = a[0]; 
    rep1(j,n){
      
      if(i>>(j-1)&1){
        bxor = bxor ^ bor; 
        bor = a[j];
      }else{
        bor = bor | a[j]; 
      }
    }
    bxor = bxor ^ bor; 
    ans = min(bxor, ans);
  }
  cout << ans << endl;
  return 0;
}