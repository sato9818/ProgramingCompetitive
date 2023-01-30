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
    int n,l;
    cin >> n >> l;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    
    ll ans = LINF;
    rep(i,n){
        ll center = l - a[i];
        int nearest = lower_bound(a.begin(), a.end(), center) - a.begin();

        // cout << i << ":" << center << ":" << nearest << endl;
        
        if(nearest == n){
            nearest--;
        }else if(nearest > 0){
            if(abs(a[nearest-1] - center) < abs(a[nearest] - center)){
                nearest--;
            }
        }
        // cout << a[nearest] << endl;
        ll path = (ll)max(a[i] + a[nearest], l-a[i] + l-a[nearest]) * 2;
        if(path < ans){
            // cout << path << endl;
            ans = path;
        }
    }

    cout << ans << endl;

    return 0;
}
