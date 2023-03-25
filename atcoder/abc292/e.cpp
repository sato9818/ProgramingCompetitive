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

    vector<vector<int>> v(n, vector<int>(n, 0));

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        e[a].push_back(b);
        v[a][b] = 1;
    }

    queue<P> q;
    rep(i,n){
        q.push(P(i, -1));
    }

    vector<vector<int>> visited(n, vector<int>(n, 0)); 

    ll cnt = 0;
    while(!q.empty()){
        P p = q.front();
        q.pop();
        int now = p.first;
        int prev = p.second;
        if(prev != -1 && visited[now][prev] == 1){
            continue;
        }else if(prev != -1){
            visited[now][prev] = 1;
        }
        
        for(auto next: e[now]){
            if(prev == -1){
                q.push(P(next, now));
            }else{
                if(next != prev && v[prev][next] == 0){
                    cnt++;
                    // cout << "prev:next " << prev << ":" << next << endl;
                    v[prev][next] = 1;
                    q.push(P(next, prev));
                }
                q.push(P(next, now));
            }
        }
    }
    cout << cnt << endl;


    return 0;
}
