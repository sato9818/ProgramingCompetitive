#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// Snuke is a great magician who can learn the spell (a,b) for any pair of integers (a,b) of his choice. The number of spells he can learn is also unlimited.
// To be able to travel between the towns using spells, he has decided to learn some number of spells so that it is possible to do the following for every pair of different towns (i,j).

// Choose just one spell among the spells learned. Then, repeatedly use just the chosen spell to get from Town i to Town j.

int main() {
  int n;
  cin >> n;
  map<P, int> mp;
  vector<P> p(n);

  rep(i,n){
    int a, b;
    cin >> a >> b;
    p[i] = P(a, b);
  }

  rep(i,n){
    for(int j=i+1;j<n;j++){
      P p1 = p[i];
      P p2 = p[j];
      int x = p[i].first - p[j].first;
      int y = p[i].second - p[j].second;
      int g = gcd(x, y);
      x /= g;
      y /= g;
      mp[P(x, y)]++;
      mp[P(-x, -y)]++;
    }
  }

  cout << mp.size() << endl;

  return 0;
}
