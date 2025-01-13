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
    int n, m, k;
    cin >> n >> m >> k;
    BIT bit(2005);

    vector<int> a;
    rep(i,n){
        int x;
        cin >> x;
        if(x != 0) {
            a.push_back(x);
        };
    }
    int zero = n - a.size();

    for(auto num : a){
        bit.add(num, 1);
    }

    rep(i,zero) {
        rep1(j, m+1) {
            int cnt = bit.sum(j);
            bit.add(j, cnt);
        }
    }


    return 0;
}
