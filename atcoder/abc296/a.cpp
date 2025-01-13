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
    string s;
    cin >> s;
    char ch = s[0];
    rep1(i,n){
        if(ch == s[i]){
            cout << "No" << endl;
            return 0;
        }
        ch = s[i];
    }
    cout << "Yes" << endl;

    return 0;
}
