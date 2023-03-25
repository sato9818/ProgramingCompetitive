#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

template <typename T>
vector<pair<T, T>> prime_factor(T n) {
    vector<pair<T, T>> ret;
    for (T i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        T tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        ret.push_back(make_pair(i, tmp));
    }
    if (n != 1) ret.push_back(make_pair(n, 1));
    return ret;
}

int main() {
    int n;
    cin >> n;
    int half = n / 2;
    map<int,int> mp;
    ll ans = 0;
    rep1(i, n+1) {
        auto pf = prime_factor(i);
        ll sum = 1;
        for(auto p: pf){
            sum *= (p.second + 1);
        }
        mp[i] = sum;
    }
    rep(i, n+1){
        ans += mp[i] * mp[n-i];
    }

    cout << ans << endl;
    

    return 0;
}
