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
    int n,m;
    cin >>n >> m;
    vector<int> p(n), l(m), d(m);
    rep(i,n) cin >> p[i];
    rep(i,m) cin >> l[i];
    rep(i,m) cin >> d[i];
    vector<P> coupons(m);
    rep(i,m) coupons[i] = P(l[i], d[i]);
    sort(coupons.begin(), coupons.end(), [](P a, P b){
        return a.first < b.first || (a.first ==b.first && a.second>b.second);
    });
    // for(auto [k,v]: coupons){
    //     cout << k << ' ' << v << endl;
    // }
    sort(p.begin(), p.end());

    ll ans = 0;
    int ci = 0;
    priority_queue<int> available;
    rep(i,n){
        while(ci < m && coupons[ci].first <= p[i]){
            available.push(coupons[ci].second);
            ci++;
        }
        if(!available.empty()){
            ans += (p[i] - available.top());
            available.pop();
        } else {
            ans += p[i];
        }
        
    }

    cout << ans << endl;


    return 0;
}
