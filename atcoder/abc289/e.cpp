#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

struct State {
    P pos;
    int cnt;
    State(P pos, int cnt) : pos(pos), cnt(cnt) {};
};

int main() {
    int t;
    cin >> t;
    rep(ii,t){
        int n,m;
        cin >> n >> m;
        vector<int> c(n);
        rep(i,n) cin >> c[i];

        vector<vector<int>> v(n);
        rep(i,m){
            int a,b;
            cin >> a >> b;
            a--; b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        if(c[0] == c[n-1]){
            cout << -1 << endl;
            continue;
        }

        vector<vector<int>> visited(2001, vector<int>(2001, 0));
        queue<State> q;
        q.push(State(P(0,n-1), 0));
        int flag = 0;
        while(!q.empty()){
            State s = q.front();
            q.pop();
            
            if(visited[s.pos.first][s.pos.second] > 0) continue;
            visited[s.pos.first][s.pos.second] = s.cnt;
            if(s.pos.first == n-1 && s.pos.second == 0){
                cout << s.cnt << endl;
                flag = 1;
                break;
            }
            for(auto e1 : v[s.pos.first]){
                for(auto e2 : v[s.pos.second]){
                    if(c[e1] != c[e2]){
                        q.push(State(P(e1, e2), s.cnt + 1));
                    }
                }
            }
        }
        if(!flag) cout << -1 << endl;
    }

    return 0;
}
