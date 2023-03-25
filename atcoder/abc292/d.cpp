#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

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
    int n,m;
    cin >> n >> m;

    vector<int> as(m), bs(m), cnt(n);

    UnionFind uf(n);

    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        as[i] = a;
        bs[i] = b;
        cnt[a]++;
        cnt[b]++;
        uf.unite(a,b);
    }

    rep(i,n){
        if(cnt[i] == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    // if(m == 0){
    //     cout << "No" << endl;
    //     return 0;
    // }

    map<int, int> mp;

    rep(i,m){
        mp[uf.root(as[i])]++;
    }

    for(auto [k,v] : mp){
        if(v != uf.size(k)){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
