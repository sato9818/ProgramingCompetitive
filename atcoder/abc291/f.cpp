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
    vector<string> paths(n);
    rep(i,n){
        cin >> paths[i];
    }
    
    vector<int> dis(n,INF), dis2(n,INF);
    // cout << dis[0] << endl;

    dis2[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        rep(i,m){
            if(v+i+1 >= n){
                continue;
            }
            char ch = paths[v][i];
            if(ch == '1'){
                if(dis2[v+i+1] > dis2[v] + 1){
                    dis2[v+i+1] = dis2[v] + 1;
                    q.push(v+i+1);
                }
            }
        }
    }
    dis[n-1] = 0;
    q.push(n-1);
    while(!q.empty()){
        int v = q.front(); q.pop();
        rep(i,m){
            if(v-i-1 < 0) {
                continue;
            }
            char ch = paths[v-i-1][i];
            if(ch == '1'){
                // cout << v-i-1 << endl;
                if(dis[v-i-1] > dis[v] + 1){
                    dis[v-i-1] = dis[v] + 1;
                    q.push(v-i-1);
                }
            }
        }
    }

    int min_dis = dis[0];
    if(min_dis >= INF){
        for(int i = 1; i<n-1; i++){
            cout << -1 << " ";
        }
        cout << endl;
        return 0;
    }
    // rep(i,n){
    //     cout << dis[i] << " ";
    // }
    // cout << endl;
    // rep(i,n){
    //     cout << dis2[i] << " ";
    // }
    // cout << endl;
    

    for(int i = 1; i<n-1; i++){
        if(dis[i] + dis2[i] != min_dis){
            cout << min_dis << " ";
            continue;
        }
        int mn = INF;
        rep(j,m) {
            if(i-j-1 < 0) {
                continue;
            }
            rep(k,m){
                if(i-j+k >= n || i-j+k <= i){
                    continue;
                }
                if(paths[i-j-1][k] == '1' && k != j){
                    mn = min(mn, dis2[i-j-1] + dis[i-j+k]+1);
                }
            }
        }
        
        if(mn >= INF){
            cout << -1 << " ";
        }else{
            cout << mn << " ";
        }
    }
    cout << endl;
    

    return 0;
}
