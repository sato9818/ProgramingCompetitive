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
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    vector<P> ans(n);

    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int leaf = 1;

    auto dfs = [&](auto f, int pre, int node) -> P {
        if(e[node].size() == 1 && e[node][0] == pre){
            ans[node] = P(leaf,leaf);
            leaf++;
            return ans[node];
        }
        P res = P(INT_MAX, INT_MIN);
        for(auto next : e[node]){
            // cout << node << " " << next << endl;
            if(next == pre){
                continue;
            }
            P sub = f(f, node, next);
            res.first = min(res.first, sub.first);
            res.second = max(res.second, sub.second);
        }
        ans[node] = res;
        return res;
    };

    dfs(dfs, -1, 0);

    rep(i,n){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
