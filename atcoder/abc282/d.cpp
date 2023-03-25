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
    vector<vector<int>> e(n);
    vector<int> visited(n,-1);

    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    ll ans1 = 0, ans2 = 0;

    rep(i,n){
        if(visited[i] > -1) continue;
        int cnt = 0;
        vector<int> ccnt(2,0);
        queue<P> q;
        q.push(P(i,0));
        while(!q.empty()){
            P v = q.front(); q.pop();
            int now = v.first;
            int color = v.second;
            if(visited[now] > -1){
                if(visited[now] == color) continue;
                cout << 0 << endl;
                return 0;
            }
            visited[now] = color;
            cnt++;
            // cout << cnt << endl;
            ccnt[color]++;
            for(auto next : e[now]){
                // cout << next << ":" << (color+1)%2 << endl;
                q.push(P(next, (color+1)%2));
            }
        }
        ans1 += (ll)(n-cnt) * (ll)cnt;
        ans2 += (ll)ccnt[0] * (ll)ccnt[1];
    }

    cout << ans1/2 + ans2 - m << endl;

    

    return 0;
}
