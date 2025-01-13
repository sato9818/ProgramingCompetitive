#include <bits/stdc++.h>
#include<atcoder/all>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
using mint = modint998244353;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n;
    cin >> n;
    map<int, mint> dp;
    dp[1] = 1;
    mint prob = mint(1) / 5;
    cout << prob << endl;

    // while(dp.size()) {
    //     auto it = dp.begin();
    //     int x = it->first;
    //     mint v = it->second;
    //     if(x >= n) {
    //         break;
    //     }
    //     dp.erase(it);
    //     if(x == n) {
    //         cout << v.val() << endl;
    //         return 0;
    //     }
        
    // }

    return 0;
}

