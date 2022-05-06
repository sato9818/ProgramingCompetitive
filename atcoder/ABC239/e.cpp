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
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    
    vector< vector<int> > e(n);

    rep(i,n){
        cin >> x[i];
    }

    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<P> query(q);

    rep(i,q){
        int v, k;
        cin >> v >> k;
        v--;
        k--;
        query[i] = P(v, k);
    }

    auto merge = [&](vector<int> &a, vector<int> b){
        a.insert(a.end(), b.begin(), b.end());
        sort(a.rbegin(), a.rend());
        a.resize(20);
    };

    vector<vector<int>> s(n);

    auto dfs = [&](auto f, int prev, int node) -> vector<int> {
        vector<int> base{x[node]};
        if(e[node].size() == 1 && e[node][0] == prev){
            s[node] = base;
            return base;
        }

        for(auto next : e[node]){
            if(next == prev){
                continue;
            }
            merge(base, f(f, node, next));
        }
        s[node] = base;
        return base;
    };

    dfs(dfs, -1, 0);

    rep(i,q){
        int v = query[i].first;
        int k = query[i].second;
        cout << s[v][k] << endl;
    }


    return 0;
}
