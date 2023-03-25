#include <bits/stdc++.h>
#define rep(i,n) for (long long i=0;i<(n);i++)
#define rep1(i,n) for (long long i=1;i<(n);i++)
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

    map<int, vector<int>> mp;

    rep(i,n){
        mp[a[i]].push_back(i);
    }

    map<int, vector<ll>> cum;

    for(auto [k,v] : mp){
        int cum_sum = 0;
        rep(i,v.size()){
            cum_sum += (n-v[i]);
        }
        rep(i,v.size()){
            cum[k].push_back(cum_sum);
            cum_sum -= (n-v[i]);
        }
    }

    ll sum = 0;

    rep(l,n-1){
        vector<int> same = mp[a[l]];
        if(l+1 > n-l-1){
            int idx = lower_bound(same.begin(), same.end(), l+1) - same.begin();
            if(cum[a[l]].size() == idx){
                sum += (n-l-1) * (n-l) / 2;
                continue;
            }
            sum += (n-l-1) * (n-l) / 2 - cum[a[l]][idx];
        }else{
            int lower_idx = lower_bound(same.begin(), same.end(), l) - same.begin();
            int upper_idx = lower_bound(same.begin(), same.end(), n-l-1) - same.begin();
            // cout << "lower_idx: " << lower_idx << " upper_idx: " << upper_idx << " l: " << l << endl;
            int same_num = upper_idx - lower_idx - 1;
            // cout << "same_num: " << same_num << endl;
            sum += (n - 2*l - 1 - same_num) * (l+1);
            // cout << "sum: " << sum << endl;
            if(cum[a[l]].size() == upper_idx){
                sum += (l) * (l+1) / 2;
                continue;
            }
            // cout << cum[a[l]][upper_idx] << endl;
            sum += (l) * (l+1) / 2 - cum[a[l]][upper_idx];
        }
        // cout << "l: " << l << " sum: " << sum << endl;
    }

    cout << sum << endl;



    return 0;
}
