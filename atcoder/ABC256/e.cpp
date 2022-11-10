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
    int n;
    cin >> n;
    vector<int> x(n),c(n);
    vector<int> cnt(n);
    ll sum = 0;
    rep(i,n){
        cin >> x[i];
        x[i]--;
        cnt[x[i]]++;
    }
    rep(i,n) cin >> c[i];
    priority_queue<P, vector<P>, greater<P>> q;
    rep(i,n){
        if(cnt[i] == 0){
            q.push(P(cnt[i], i));   
        }
    }

    vector<int> visited(n,0);
    
    while(!q.empty()){
        P p = q.top(); q.pop();
        int hated = p.first, idx = p.second;
        // cout << idx << endl;
        if(visited[idx]){
            continue;
        }
        visited[idx] = 1;
        cnt[x[idx]]--;
        if(cnt[x[idx]] == 0){
            q.push(P(cnt[x[idx]], x[idx]));
        }
    }
    // rep(i,n){
    //     cout << cnt[i] << " " << visited[i] << endl;
    // }
    
    rep(i,n){
        if(!visited[i]) {
            int mn = INF;
            int next = i;
            while(!visited[next]){
                // cout << next << endl;
                mn = min(mn, c[next]);
                visited[next] = 1;
                next = x[next];
            }
            sum += (ll)mn;
        }
    }

    cout << sum << endl;

    return 0;
}
