#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;

struct Edge{
  int from, to, cost, num;
  Edge(int from, int to, int cost): from(from), to(to), cost(cost){}
  Edge(int from, int to, int cost, int num): from(from), to(to), cost(cost), num(num){}
};

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
  int n, m, q;
  cin >> n >> m >> q;
  vector<Edge> e;
  rep(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    e.emplace_back(a, b, c);
  }

  sort(e.begin(),e.end(), [](Edge a, Edge b){
    return a.cost < b.cost;
  });
  e.emplace_back(0,0,1001001001);
  vector<Edge> query;

  rep(i,q){
    int u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    query.emplace_back(u,v,w,i);
  }

  sort(query.begin(),query.end(), [](Edge a, Edge b){
    return a.cost < b.cost;
  });

  query.emplace_back(0,0,1001001001,-1);

  UnionFind uf(n);

  vector<int> ans(q,0);
  int ei = 0;
  int qi = 0;
  Edge ee = e[ei];
  Edge qe = query[qi];
  while(true){
    if(ei == m && qi == q){
      break;
    }
    if(ee.cost < qe.cost){
      if(!uf.same(ee.from, ee.to)){
        uf.unite(ee.from, ee.to);
      }
      ei++;
      ee = e[ei];
    }else{
      if(!uf.same(qe.from, qe.to)){
        ans[qe.num] = 1;
      }
      qi++;
      qe = query[qi];
    }

  }

  rep(i,q){
    if(ans[i] == 0){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
  }


  
  return 0;
}
