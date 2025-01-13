#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int is_equal(char c1, char c2){
    if(c1 == '0' && c2 == 'o') return 1;
    if(c1 == 'o' && c2 == '0') return 1;
    if(c1 == '1' && c2 == 'l') return 1;
    if(c1 == 'l' && c2 == '1') return 1;
    return 0;
}

int main() {
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    rep(i,n){
        if(s[i] != t[i] && !is_equal(s[i], t[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
