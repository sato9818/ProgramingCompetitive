#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

ll check = 0;

ll dfs(vector<vector<int>>& v, int now, vector<int>& visited){
    if(check == 1){
        return 1000000;
    }
    ll sum = 1;
    for(auto next : v[now]){
        if(visited[next] == 0){
            visited[next] = 1;
            sum += dfs(v, next, visited);
            visited[next] = 0;
        }
    }

    if(sum > 1000000) {
        check = 1;
    }
    return sum;
}

int main() {

    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n);

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> visited(n,0);
    visited[0] = 1;
    ll ans = dfs(v, 0, visited);
    if(check == 0) cout << ans << endl;
    else cout << 1000000 << endl;

    

    return 0;
}
