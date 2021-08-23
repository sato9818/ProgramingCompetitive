#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
using PP = pair<int, P>;


struct UnionFind {
  vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
  vector<ll> siz;

  UnionFind(ll N) : par(N), siz(N, 1LL) { //最初は全てが根であるとして初期化
    for(ll i = 0; i < N; i++) par[i] = i;
  }

  ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(ll x, ll y) { // xとyの木を併合
    ll rx = root(x); //xの根をrx
    ll ry = root(y); //yの根をry
    if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
    if (siz[ry] < siz[rx]) swap(rx, ry);
    siz[ry] += siz[rx];
    par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
    ll rx = root(x);
    ll ry = root(y);
    return rx == ry;
  }
  
  ll size(ll x) { // 素集合のサイズ
    return siz[root(x)];
  }
};

int main() {
  int n;
  cin >> n;

  UnionFind u(n);

  vector<PP> path(n-1);

  rep(i,n-1){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    path[i] = PP(w, P(u,v));
  }

  sort(path.begin(), path.end());

  ll ans = 0;
  rep(i,n-1){
    PP p = path[i];
    int cost = p.first;
    ans += u.size(p.second.first) * u.size(p.second.second) * cost;
    u.unite(p.second.first, p.second.second);
  }

  cout << ans << endl;
  
  return 0;
}
