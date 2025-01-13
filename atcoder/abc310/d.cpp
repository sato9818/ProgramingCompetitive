#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

void dfs(int n, int t, int &ans, vector<vector<int>>& hate, vector<vector<int>>& teams, int now){
    if(now == n) {
        if(teams.size() == t) {
            // rep(i,teams.size()) {
            //     rep(j,teams[i].size()) {
            //         cout << teams[i][j] + 1 << " ";
            //     }
            //     cout << endl;
            // }
            ans++;
        }
        return;
    }
    int teams_siz = teams.size();
    rep(i,teams_siz) {
        int siz = teams[i].size();
        int flag = 0;
        rep(j,siz) {
            if(hate[now][teams[i][j]] == 1) {
                // cout << now +1 << " " << teams[i][j]+1 << endl;
                flag = 1;
                break;
            }
            
        }

        if(flag) continue;
        teams[i].push_back(now);
        dfs(n, t, ans, hate, teams, now+1);
        teams[i].pop_back();
    }
    if(teams_siz < t) {
        teams.push_back({now});
        dfs(n, t, ans, hate, teams, now+1);
        teams.pop_back();
    }
}

int main() {
    int n,t,m;
    cin >> n >> t >> m;
    vector<vector<int>> hate(n, vector<int>(n, 0)), teams; 
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        hate[a][b] = 1;
        hate[b][a] = 1;
    }

    int ans = 0;
    dfs(n, t, ans, hate, teams, 0);

    cout << ans << endl;

    return 0;
}
