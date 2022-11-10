#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

string ans = "";
bool dfs(vector<string>& strs, map<string, int>& exs, vector<int>& indexes, int under_bar, int idx, string sub_str){
    bool included = true;
    sub_str += strs[indexes[idx]];
    if(sub_str.size() > 16){
        return included;
    }
    
    if(idx == strs.size() - 1){
        if(sub_str.size() < 3){
            return true;
        }
        if(exs.count(sub_str) > 0){
            return true;
        }else{
            ans = sub_str;
            return false;
        }
    }
    
    sub_str += '_';
    rep(i,under_bar+1){
        
        included &= dfs(strs, exs, indexes, under_bar-i, idx+1, sub_str);
        sub_str += '_';
    }
    return included;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> strs(n);
    int sum_len = n-1;
    rep(i,n){
        cin >> strs[i];
        sum_len += strs[i].size();
    }


    map<string, int> exs;

    rep(i,m){
        string t;
        cin >> t;
        exs[t] = 1;
    }

    vector<int> indexes;
    rep(i,n){
        indexes.push_back(i);
    }

    do {
        if(!dfs(strs, exs, indexes, 16 - sum_len, 0, "")){
            cout << ans << endl;
            return 0;
        }
    } while( next_permutation(indexes.begin(), indexes.end()));

    cout << "-1" << endl;
    return 0;
}
