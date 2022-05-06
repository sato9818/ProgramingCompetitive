#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

vector<int> getDivisors(int n){
    vector<int> res;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    unordered_map<int, int> mp;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    
    ll ans = 0;
    rep(i,n){
        vector<int> divisors = getDivisors(a[i]);
        // cout << "num: " << a[i] << endl;
        rep(j,divisors.size()){
            // cout << divisors[j] << endl;
            
            if(divisors[j] * divisors[j] == a[i]){
                ans += (ll)mp[divisors[j]] * mp[divisors[j]];
            }else{
                ans += (ll)mp[divisors[j]] * mp[a[i]/divisors[j]] * 2;
            }
            
        }
        // cout << "ans:" << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
