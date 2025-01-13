#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    ll w, h, n;
    cin >> w >> h >> n;

    vector<P> straw(n);
    rep(i,n) {
        ll p,q;
        cin >> p >> q;
        straw[i] = P(p,q);
    }

    
    vector<ll> xs, ys;
    xs.push_back(0);
    ys.push_back(0);

    ll a;
    cin >> a;

    rep(i,a){
        int x;
        cin >> x;
        xs.push_back(x);
    }
    ll b;
    cin >> b;

    rep(i,b){
        int y;
        cin >> y;
        ys.push_back(y);
    }

    map<P, int> cnt;

    int mx = 0, mn = INF;

    rep(i,n){
        ll x = straw[i].first;
        ll y = straw[i].second;
        int area_x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        int area_y = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
        
        area_x--;
        area_y--;
        // cout << area_x << " " << area_y << endl;
        cnt[P(area_x, area_y)]++;
        mx = max(mx, cnt[P(area_x, area_y)]);
    }
    ll num = cnt.size();
    if((ll)(a+1)*(b+1) != num){
        cout << 0 << " ";
    }else{
        for(auto [k,v] : cnt){
            mn = min(mn, v);
        }
        
        cout << mn << " ";
    }

    cout << mx << endl;



    return 0;
}
