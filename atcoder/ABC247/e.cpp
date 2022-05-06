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
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> a(n);
    vector<vector<int>> ranges;
    rep(i,n){
        cin >> a[i];
    }
    vector<int> range;

    rep(i,n){
        if(y<=a[i] && a[i]<=x){
            range.push_back(a[i]);
        }else{
            if(range.size() != 0){
                ranges.push_back(range);
                range.clear();
            }
        }
    }

    if(range.size() != 0){
        ranges.push_back(range);
        range.clear();
    }

    auto get_comb = [&](vector<int>& v) -> ll {
        int l = 0, r = 0;
        int m = v.size();
        // cout << m << endl;a
        map<int,int> cnt;
        ll sum = 0;
        while(r < m || (cnt[x] > 0 && cnt[y] > 0)){
            // cout << l << ":" << r << endl;
            if(cnt[x] > 0 && cnt[y] > 0){
                sum += m - r + 1;
                cnt[v[l]]--;
                l++;
            }else{
                cnt[v[r]]++;
                r++;
            }
        }
        return sum;
    };

    ll ans = 0;
    rep(i,ranges.size()){
        ans += get_comb(ranges[i]);
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
