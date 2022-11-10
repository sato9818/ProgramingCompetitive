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
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    map<int,int> m;
    m[a] = 1;
    m[b] = 1;
    m[c] = 1;
    m[d] = 1;
    m[e] = 1;

    cout << m.size() << endl; 
    return 0;
}
