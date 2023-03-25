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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> indegree(n,0);
    map<P, int> mp;

    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(mp[P(a,b)]) continue;
        mp[P(a,b)] = 1;
        e[a].push_back(b);
        indegree[b]++;
    }

    vector<int> done;

    queue<int> q;
    rep(i,n) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    if(q.size() > 1){
        cout << "No" << endl;
        return 0;
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();
        done.push_back(v);
        int cnt = 0;
        for(auto nv : e[v]){
            indegree[nv]--;
            if(indegree[nv] == 0){
                q.push(nv);
                cnt++;
                if(cnt > 1){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    if(done.size() != n){
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    vector<int> ans(n);
    rep(i,n){
        ans[done[i]] = i+1;
    }
    rep(i,n){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}
