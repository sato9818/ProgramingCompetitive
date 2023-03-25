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
    ll n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    map<int, int> mp;
    rep(i,n){
        mp[a[i]]++;
    }

    ll same = 0;
    auto c2 = [&](ll x) -> ll {
        return x * (x-1) / 2;
    };

    for(auto [k,v]: mp) same += c2(v);

    ll sum = 0;

    rep(i,n){
        int l = i, r = n-1-i;
        if(l >= r) break;
        sum += c2(n - 2 * i) - same;
        same -= c2(mp[a[l]]);
        mp[a[l]]--;
        same += c2(mp[a[l]]);
        same -= c2(mp[a[r]]);
        mp[a[r]]--;
        same += c2(mp[a[r]]);
    }

    cout << sum << endl;


    return 0;
}
