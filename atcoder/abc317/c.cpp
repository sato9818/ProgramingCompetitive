#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n,m;
    cin >> n >> m;

    vector<set<int>> e(n);
    map<P, ll> mp;

    rep(i,m) {
        int a,b;
        ll c;
        cin >> a >> b >> c;
        --a; --b;
        e[a].insert(b);
        e[b].insert(a);
        mp[P(a,b)] = c;
        mp[P(b,a)] = c;
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    ll mx = 0;
  
  do{
    ll sum = 0;
    int now = p[0];
    bool flag = false;
    rep1(i,n) {
        if(e[now].find(p[i]) == e[now].end()) {
            flag = true;
            break;
        }
        sum += mp[P(now,p[i])];
        now = p[i];
    }
    mx = max(mx, sum);
  }while(next_permutation(p.begin(),p.end()));

  cout << mx << endl;



    return 0;
}
