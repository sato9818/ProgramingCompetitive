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

    string str;
    cin >> str;
    // ACE、BDF、CEG、DFA、EGB、FAC、GBD
    set<string> st = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    if (st.count(str)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
