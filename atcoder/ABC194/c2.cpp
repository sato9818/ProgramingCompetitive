#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  map<int,int> m;
  rep(i,n){
    m[a[i] + 200]++;
  }
  ll sum=0;
  for(int i=0;i<401;i++){
    for(int j=i;j<401;j++){
      sum += (ll)m[i] * m[j] * ((i-200)-(j-200)) * ((i-200)-(j-200));
    }
  }

  cout << sum << endl;
  
  return 0;
}