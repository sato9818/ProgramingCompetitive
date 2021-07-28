#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PP = pair<pair<int, int>, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<PP> city(m);
  vector<string> id(m);
  rep(i,m){
    int p, y;
    cin >> p >> y;
    city[i] = PP(P(p,y),i);
  }
  sort(city.begin(), city.end());

  int cnt = 1;
  int num = 1;
  rep(i,m){
    if(num != city[i].first.first){
      num = city[i].first.first;
      cnt = 1;
    }
    stringstream ss;
    ss << setw(6) << setfill('0') << num << setw(6) << setfill('0') << cnt;
    id[city[i].second] = ss.str();
    cnt++;
  }

  rep(i,m){
    cout << id[i] << endl;
  }

  return 0;
}
