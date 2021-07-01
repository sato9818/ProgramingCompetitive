#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n, m;
  cin >> n >> m;
  vector< vector<int> > p(n);
  vector<int> cnt(n+1, 0);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    p[a].push_back(b);
    p[b].push_back(a);
  }
  
  cout << endl;
  return 0;
}