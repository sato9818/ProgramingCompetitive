#include <bits/stdc++.h>
#include <unordered_set>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  map<ll, int> m;
  for(ll i=2;i*i<=n;i++){
    ll a = i * i;
    while(1){
      if(a <= n){
       m[a] = 1;
      }else{
        break;
      }
      a *= i;
    }
  }
  
  cout << n-m.size() << endl;
  return 0;
}