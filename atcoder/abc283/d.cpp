#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool ans = false;


int dfs(set<char>& st, string& s, int i) {
    if(i >= s.size()){
        return i;
    }
    

    if(s[i] == '(') {
        i = dfs(st, s, i+1);
        return dfs(st, s, i+1);
    }

    if(s[i] == ')') {
        return i;
    }

    if(st.find(s[i]) != st.end()) {
        ans = true;
        return s.size();
    }

    st.insert(s[i]);
    int j = dfs(st, s, i+1);
    st.erase(s[i]);
    return j;
}

int main() {
    string s;
    cin >> s;
    set<char> st;
    dfs(st, s, 0);
    if(!ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
