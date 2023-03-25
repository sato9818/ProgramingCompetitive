#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

void dfs(vector<string>& strs, vector<int>& ans, int idx, vector<int>& group){

    if(group.size() == 1){
        ans[group[0]] = idx-1;
        return;
    }
    vector<vector<int>> alpha(26);
    for(auto i : group){
        if(strs[i].size() <= idx){
            ans[i] = strs[i].size();
            continue;
        }
        alpha[strs[i][idx] - 'a'].push_back(i);
    }
    rep(i,26){
        if(alpha[i].size() == 0) continue;
        dfs(strs, ans, idx+1, alpha[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    rep(i,n) cin >> strs[i];

    vector<int> ans(n);
    vector<int> indices(n);
    rep(i,n) indices[i] = i;

    dfs(strs, ans, 0, indices);

    rep(i,n) cout << ans[i] << endl;


    return 0;
}
