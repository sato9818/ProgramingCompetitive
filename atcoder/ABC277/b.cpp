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
    set<char> first{'H' , 'D' , 'C' , 'S'}, second{'A' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , 'T' , 'J' , 'Q' , 'K'};
    set<string> st;

    bool ok = 1;

    rep(i,n){
        string s;
        cin >> s;
        st.insert(s);
        if(first.find(s[0]) == first.end() || second.find(s[1]) == second.end()){
            ok = 0;
        }
    }

    if(ok && st.size() == n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
