#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int l, q;
  cin >> l >> q;

  set<int> s;

  s.insert(0);
  s.insert(l);

  rep(i,q){
    int c, x;
    cin >> c >> x;

    if(c == 1){
      s.insert(x);
    }else{
      auto upp = s.upper_bound(x);

      cout << (*upp - *prev(upp, 1)) << endl;
    }
  }


  
  return 0;
}
