#include <bits/stdc++.h>
#include<atcoder/all>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
using mint = modint998244353;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    ll n;
    cin >> n;
    map<ll, mint> dp;
    dp[1] = 1;
    mint prob = mint(1) / 5;

    while(dp.size()) {
        auto it = dp.begin();
        ll x = it->first;
        mint v = it->second;
        if(x == n) {
            cout << v.val() << endl;
            break;
        }else if(x > n){
            cout << 0 << endl;
            break;
        }
        dp.erase(it);
        for(int i=2;i<7;i++){
            dp[x*i] += v * prob;
        }
    }

    return 0;
}

