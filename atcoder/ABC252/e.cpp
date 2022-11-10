#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using PP = pair<ll, P>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> e(n);
    map<P, int> mp;

    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        e[a].push_back(P(b,c));
        e[b].push_back(P(a,c));
        mp[P(a,b)] = i;
        mp[P(b,a)] = i;
    }


    priority_queue<PP, vector<PP>, greater<PP>> q;
    for(auto v : e[0]){
        ll c = v.second;
        int to = v.first;
        q.push(PP(c, P(0, to)));
    }
    
    vector<int> visited(n,0);
    visited[0] = 1;
    vector<int> ans;
    while(!q.empty()){
        PP p = q.top(); q.pop();
        ll c = p.first;
        int from = p.second.first;
        int to = p.second.second;
        if(visited[to]) continue;
        ans.push_back(mp[P(from,to)]);
        visited[to] = 1;
        for(auto v : e[to]){
            int new_dis = v.first;
            if(visited[new_dis]) continue;
            ll new_cost = c + v.second;
            q.push(PP(new_cost, P(to, new_dis)));
        }
    }

    rep(i,ans.size()){
        cout << ans[i]+1 << endl;
    }

    return 0;
}
