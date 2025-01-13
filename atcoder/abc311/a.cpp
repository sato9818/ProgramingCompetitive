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
    string str;
    cin >> str;
    set<char> st = {'A', 'B', 'C'};
    rep(i,n) {
        if (st.count(str[i])) {
            st.erase(str[i]);
        } 
        if(st.empty()) {
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}
