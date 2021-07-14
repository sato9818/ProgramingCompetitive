#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  map<int,int> circle;
  vector<int> f(n);
  rep(i,n){
    cin >> f[i];
  }
  int cnt = 0;
  rep(i,n){
    map<int,int> m;
    int x = f[i] - 1;
    while(1){
      if(m[x] > 0){
        cnt++;
        break;
      }
      if(circle[x] > 0){
        break;
      }
      
      // if(m[x] > 0){
      //   cnt++;
      //   while(1){
      //     if(circle[x]>0){
      //       break;
      //     }
      //     circle[x]++;
      //     x = f[x] - 1;
      //   }
      //   break;
      // }
      m[x]++;
      circle[x]++;
      x = f[x] - 1;
    }
  }
  ll ans = 1;
  
  rep(i,cnt){
    ans *= 2;
    ans %= 998244353;
  }
  
  cout << (ans - 1) % 998244353 << endl;
  return 0;
}