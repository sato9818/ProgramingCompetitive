#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

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

ll min_fact(P p) {
    ll prime = p.first;
    ll cnt = p.second;
    ll ans = 0;

    while(cnt > 0) {
        ans += prime;
        ll num = ans;
        while(num%prime == 0) {
            num /= prime;
            cnt--;
        }
    }
    return ans;
}

int main() {
    ll k;
    cin >> k;
    vector<P> pf = prime_factor(k);
    ll ans = 2;
    for(auto p : pf) {
        ans = max(ans, min_fact(p));
    }
    cout << ans << endl;

    return 0;
}
