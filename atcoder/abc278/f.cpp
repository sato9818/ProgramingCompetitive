#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool dfs(vector<vector<int>>& memo, int visited, vector<vector<int>> &s, string str, vector<string>& words){
    char last_char = str[str.size()-1];
    // cout << bitset<8>(visited) << " : " << str << endl;
    if(memo[visited][last_char - 'a'] != -1){
        return memo[visited][last_char - 'a'];
    }

    if(s[last_char - 'a'].size() == 0){
        return memo[visited][last_char - 'a'] = false;
    }
    
    bool ans = true;
    int cnt = 0;
    for(auto index : s[last_char - 'a']){
        if((visited >> index) & 1){
            continue;
        }
        cnt++;
        visited += (1 << index);
        ans &= dfs(memo, visited, s, words[index], words);
        visited -= (1 << index);
    }
    if(cnt == 0){
        return memo[visited][last_char - 'a'] = false;
    }
    if(ans) return memo[visited][last_char - 'a'] = false;
    else return memo[visited][last_char - 'a'] = true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> s(26);
    vector<string> words(n);

    rep(i,n){
        cin >> words[i];
        s[words[i][0] - 'a'].push_back(i);
    }

    vector<vector<int>> memo(1 << n, vector<int>(26, -1));

    // cout << dfs(memo, 1, s, words[0], words) << endl;
    rep(i,n){
        if(!dfs(memo, 0 + (1<<i), s, words[i], words)){
            cout << "First" << endl;
            return 0;
        }
    }
    cout << "Second" << endl;
    


    return 0;
}
