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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if(a == n-1 || d == n-1){
        cout << "Yes" << endl;
        return 0;
    }
    if(b == 0 && c == 0){
        cout << "No" << endl;
        return 0;
    }
    if(abs(b-c) == 1 || abs(b-c) == 0){
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}
