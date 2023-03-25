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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    map<int, int> mp,mins;
    
    ll sum = 0;
    vector<int> cp = a;
    sort(cp.begin(), next(cp.begin(), m));
    rep(i,m){
        mp[cp[i]]++;
    }
    rep(i,k){
        sum += cp[i];
        mins[cp[i]]++;
        mp[cp[i]]--;
        if(mp[cp[i]] == 0){
            mp.erase(cp[i]);
        }
        // cout << sum << endl;
    }

    rep(i,n-m){
        cout << sum << " ";
        if(mins.count(a[i]) > 0){
            sum -= a[i];
            mins[a[i]]--;
            if(mins[a[i]] == 0){
                mins.erase(a[i]);
            }
            mp[a[i+m]]++;
            int mn = mp.begin()->first;
            sum += mn;
            mp[mn]--;
            mins[mn]++;
            if(mp[mn] == 0){
                mp.erase(mn);
            }
            
        }else{
            mp[a[i]]--;
            if(mp[a[i]] == 0){
                mp.erase(a[i]);
            }
            mp[a[i+m]]++;
            int mn = mp.begin()->first;
            int mx = next(mins.end(), -1)->first;
            if(mx > mn){
                sum -= mx;
                sum += mn;
                mins[mn]++;
                mins[mx]--;
                if(mins[mx] == 0){
                    mins.erase(mx);
                }
                mp[mx]++;
                mp[mn]--;
                if(mp[mn] == 0){
                    mp.erase(mn);
                }
            }
        }
        // for (auto it = mp.begin(); it != mp.end(); ++it){
        // cout << it->first << " ";
        // }
        // cout << endl;
        // for (auto it = mins.begin(); it != mins.end(); ++it){
        // cout << it->first << " ";
        // }
        // cout << endl;
    }
    cout << sum << "\n";

    return 0;
}

/*
6 4 3
3 1 4 1 5 9

mins 1 1 
mp 4 5

10 6 3
12 2 17 11 19 8 4 3 6 20

mp 11 17 19
ms 4 8 
*/

