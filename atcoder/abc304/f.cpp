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
    string d;
    cin >> n >> d;

    vector<int> p;
    for(int i = 2;i<n;i++) {
        if(n % i == 0) {
            p.push_back(i);
        }
    }
    vector<int> dots;
    rep(i,n){
        if(d[i] == '.') {
            dots.push_back(i);
        }
    }

    ll sum = 0;

    vector<ll> pow_ori(n);
    pow_ori[0] = 1;
    rep1(i,n) {
        pow_ori[i] = pow_ori[i-1] * 2;
        pow_ori[i] %= MOD;
    }

    vector<int> p_cnt()

    rep(i,p.size()) {
        map<int,int> cnt;
        rep(j,dots.size()){
            cnt[dots[j] % p[i]]++;
        }
        int num = cnt.size();
       
        ll x = (pow_ori[p[i] - num] - 1);
        cout << x << endl;
        sum += x;
        sum -= (n/p[i] - 2) * x;
        sum %= MOD;
    }

    cout << (sum + MOD + 1) % MOD << endl;
    return 0;
}
