#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int solve(vector<vector<int>> &a, set<int> goals, int n,vector<vector<int>> &v, int m){
    queue<P> q;
    
    vector<int> visited_idx(n, 0), visited_num(m,0);
    for(auto can : a[0]){
        q.push(P(can, 0));
        visited_idx[can] = 1;
    } 
    while(!q.empty()) {
        P p = q.front(); q.pop();
        int now = p.first;
        int dist = p.second;
        // cout << now << endl;
        if(goals.count(now)) return dist;
        for(int can : v[now]){
            if(visited_num[can]) continue;
            visited_num[can] = 1;
            for(int next : a[can]) {
                if(visited_idx[next]) continue;
                visited_idx[next] = 1;
                q.push(P(next, dist+1));
            }
        }
    }
    return INF;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<vector<int>> v(n);
    set<int> goals;
    rep(i,n){
        int an;
        cin >> an;
        rep(j,an){
            int s;
            cin >> s;
            s--;
            if(s == m-1) goals.insert(i);
            a[s].push_back(i);
            v[i].push_back(s);
        }
    }

    int ans = solve(a, goals, n,v, m);

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;


    

    return 0;
}
