#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int q;
  cin >> q;
  
  multiset<ll> s;
  ll plus = 0;

  rep(i,q){
    int op;
    cin >> op;
    if(op == 1){
      int x;
      cin >> x;
      s.insert(x-plus);
    }else if(op == 2){
      int x;
      cin >> x;
      plus += x;
    }else{
      auto it = s.begin();

      cout << (*it) + plus << endl;
      s.erase(it);
    }

  }
  return 0;
}
