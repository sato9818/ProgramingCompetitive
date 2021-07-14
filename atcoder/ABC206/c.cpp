#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  // vector<int> a(n);
  map<int,int> m;

  rep(i,n){
    int a;
    cin >> a;
    m[a]++;
  }
  // sort(m.begin(), m.end());

  ll sum = 0;
  for(auto x : m){
    n -= x.second;
    sum += (ll)n * x.second;
  }

  cout << sum << endl;
  return 0;
}