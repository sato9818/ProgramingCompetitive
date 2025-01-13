#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool is_tak(vector<string>& strs) {
    rep(i,3){
        rep(j,3){
            if(strs[i][j] == '.') return false;
            if(strs[8-i][8-j] == '.') return false;
        }
    }
    rep(i,4){
        if(strs[3][i] == '#') return false;
        if(strs[i][3] == '#') return false;
        if(strs[8-i][5] == '#') return false;
        if(strs[5][8-i] == '#') return false;
    }

    return true;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> strs(n);
    rep(i,n) cin >> strs[i];

    vector<P> ans;

    rep(i,n) {
        rep(j,m) {
            if(i+9 > n || j+9 > m) continue;
            vector<string> taks;
            rep(k,9){
                
                string str = "";
                rep(l,9){
                    str += strs[i+k][j+l];
                }
                taks.push_back(str);
            }
            if(is_tak(taks)) {
                ans.push_back(P(i+1, j+1));
            }
        }
    }

    rep(i,ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
