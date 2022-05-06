#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
using PP = pair<int, P>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;

int main() {
    map<int,int> m;
    m[1]++;
    m[1]--;
    cout << m.size() << endl;
    return 0;
}
