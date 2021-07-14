#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  
  vector<pair<double,double> > a(n);
  rep(i,n){
    int t;
    double l,r;
    cin >> t >> l >> r;

    if(t == 1){
      a[i] = make_pair(l,r);
    }else if(t == 2){
      a[i] = make_pair(l,r-0.1);
    }else if(t == 3){
      a[i] = make_pair(l+0.1,r);
    }else if(t == 4){
      a[i] = make_pair(l+0.1,r-0.1);
    }
  }
  ll sum = 0;
  rep(i,n){
    double xl = a[i].first, xr = a[i].second;
    for(int j = i+1;j<n;j++){
      double yl = a[j].first, yr = a[j].second;
      if((xl <= yl && yl <= xr) || (xl <= yr && yr <= xr)){
        sum++;
      }else if((yl <= xl && xl <= yr) || (yl <= xr && xr <= yr)){
        sum++;
      }
    }
  }
  
  cout << sum << endl;
  return 0;
}