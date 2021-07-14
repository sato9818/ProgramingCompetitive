#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<int> a(n),b(n);

  rep(i,n){
    cin >> a[i];
    b[i] = a[i];
  }

  ll cnt = k / n;
  int rem = k % n;

  sort(b.begin(),b.end());
  
  if(rem == 0){
    rep(i,n){
      cout << cnt << endl;
    }
    return 0;
  }
  int th = b[rem-1];

  rep(i,n){
    if(a[i] <= th){
      cout << cnt + 1 << endl;
    }else{
      cout << cnt << endl;
    }
  }
  

  return 0;
}