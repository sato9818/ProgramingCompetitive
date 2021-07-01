#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector< vector<int> > tree(n);
  vector<int> reward(n, 1);
  vector<int> expect(n,1);
  
  rep1(i,n){
    int p;
    cin >> p;
    tree[p-1].push_back(i);
  }
  const auto dfs = [&](auto &&dfs, int v) -> void{
    for()
  }
  
  return 0;
}