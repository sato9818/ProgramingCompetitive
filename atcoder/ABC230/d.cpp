#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 998244353;

int main() {
  int n, d;
  cin >> n >> d;

  vector<P> walls(n);

  rep(i,n){
    int r,l;
    cin >> l >> r;
    walls[i] = P(l,r);
  }

  sort(walls.begin(), walls.end(), [](P a, P b){
    return a.second < b.second;
  });


  // rep(i,n){
  //   cout << walls[i].first << " " << walls[i].second << endl;
  // }

  int right = walls[0].second;
  int row = 0;
  int punch_right = right + d-1;
  int ans = 1;
  while(row != n){
    int left = walls[row].first;
    if(left > punch_right){
      punch_right = walls[row].second + d-1;
      ans++;
    }
    row++;
  }

  cout << ans << endl;
  return 0;
}
