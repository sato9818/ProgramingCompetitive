#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
using PP = pair<int, pair<int, int>>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;
int target;
void dfs(int v, map<P, int>& visited, vector<vector<P>>& g, map<int,int>& s, bool cond, int cnt){
    if(visited.count(P(v, cond)) > 0 && visited[P(v, cond)] <= cnt) return;
    visited[P(v, cond)] = cnt;
    for(auto [to, c] : g[v]){
        if(cond == 0){
            if(c == 1) dfs(to, visited, g, s, cond, cnt+1);
        }else{
            if(c == 0) dfs(to, visited, g, s, cond, cnt+1);
        }
        if(s.count(v) > 0){
            if(cond == 0){
                if(c == 0) dfs(to, visited, g, s, 1, cnt+1);
            }else{
                if(c == 1) dfs(to, visited, g, s, 0, cnt+1);
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    target = n-1;
    vector<vector<P>> g(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(P(b, c));
        g[b].push_back(P(a, c));
    }   
    map<int,int> sw;
    rep(i,k) {
        int s;
        cin >> s;
        s--;
        sw[s] = 1;
    }
    
    map<P, int> visited;

    priority_queue<PP, vector<PP>, greater<PP>> q;
    q.push(PP(0, P(0,0)));
    while(!q.empty()){
        PP pp = q.top();q.pop();
        int v = pp.second.first;
        int cost = pp.first;
        int cond = pp.second.second;
        
        if(visited.count(P(v, cond)) > 0) continue;
        visited[P(v, cond)] = cost;
        // cout << v << endl;
        if(v == n - 1) {
            cout << pp.first << endl;
            return 0;
        }
        for(auto [next, c] : g[v]){
            if(cond == 0){
                if(c == 1) q.push(PP(cost+1, P(next, 0)));
            }else{
                if(c == 0) q.push(PP(cost+1, P(next, 1)));
            }
            if(sw.count(v) > 0){
                if(cond == 0){
                    if(c == 0) q.push(PP(cost+1, P(next, 1)));
                }else{
                    if(c == 1) q.push(PP(cost+1, P(next, 0)));
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
