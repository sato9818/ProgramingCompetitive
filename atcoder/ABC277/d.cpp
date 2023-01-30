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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    map<ll,ll> mp;

    rep(i,n) cin >> a[i];
    rep(i,n) mp[a[i]]++;
    ll total = 0;
    rep(i,n) total += a[i];

    ll sum = 0;
    ll ans = total;
    int prev = -1;
    for(auto [k,v] : mp){
        if(prev + 1 == k){
            sum += (ll)k * v;
        }else{
            sum = (ll)k * v;
        }
        ans = min(ans, total - sum);
        prev = k;
    }

    for(auto [k,v] : mp){
        if((prev + 1) % m == k){
            sum += (ll)k * v;
        }else{
            sum = (ll)k * v;
        }
        ans = min(ans, total - sum);
        prev = k;
    }

    cout << max(ans, (ll)0) << endl;

    return 0;
}
