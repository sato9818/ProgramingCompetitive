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
    string s;
    cin >> s;

    for(auto ch : s){
        if(ch == '0') cout << 1;
        else cout << 0;
    }
    cout << endl;

    return 0;
}
