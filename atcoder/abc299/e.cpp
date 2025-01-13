#include <bits/stdc++.h>
#include<atcoder/all>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
using mint = modint998244353;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

void find_cand(vector<vector<int>>& cands, vector<vector<int>>& e, set<int>& deny, int tar, int first, vector<int>& visited) {
    queue<P> q;
    q.push(P(first, 0));
    while(q.size()) {
        auto [now, cnt] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = 1;
        if(cnt == tar) {
            cands[first].push_back(now);
        }else{
            deny.insert(now);
        }
        
        for(auto v : e[now]) {
            if(cnt == tar) {
                break;
            }
            if(visited[v]) continue;
            q.push(P(v, cnt+1));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int k;
    cin >> k;
    vector<P> cond(k);
    rep(i,k) {
        int p,d;
        cin >> p >> d;
        p--;
        cond[i] = P(p,d);
    }

    if(k == 0) {
        cout << "Yes" << endl;
        rep(i,n) {
            cout << 1;
        }
        cout << endl;
        return 0;
    }

    vector<vector<int>> cands(n);
    set<int> deny;

    rep(i,k) {
        int p = cond[i].first;
        int d = cond[i].second;
        vector<int> visited(n,0);
        find_cand(cands, e, deny, d, p, visited);
    }

    vector<int> ans(n, 0);

    rep(i,k) {
        int flag = 0;
        for(auto v : cands[cond[i].first]){
            if(deny.count(v)) continue;
            ans[v] = 1;
            flag = 1;
            break;
        }
        if(!flag) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    rep(i,n) {
        cout << ans[i];
    }
    cout << endl;



    return 0;
}
