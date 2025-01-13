#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool dfs(int cur, int pre, vector<vector<int>>& e, vector<int>& visited, int target) {
    cout << cur + 1  << endl;
    visited[cur] = 1;
    if(cur == target) {
        return true;
    }
    
    int k;
    cin >> k;
    rep(i,k) {
        int v;
        cin >> v;
        e[cur].push_back(v-1);
    }
    
    bool ans = false;

    rep(i,k) {
        if(visited[e[cur][i]]) continue;
        ans |= dfs(e[cur][i], cur, e, visited, target);
        if(ans) return true;
    }
    if(ans) return true;
    cout << pre + 1 << endl;
    cin >> k;
    rep(i,k) {
        int v;
        cin >> v;
    }
    return false;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> e(n);
    vector<int> visited(n,0);
    visited[0] = 1;

    int k;
    cin >> k;
    rep(i,k) {
        int v;
        cin >> v;
        e[0].push_back(v-1);
    }

    rep(i,k){
        if(!visited[e[0][i]]) dfs(e[0][i], 0, e, visited, n-1);
    }

    return 0;
}
