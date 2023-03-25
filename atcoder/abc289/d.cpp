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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int m;
    cin >> m;
    map<int,int> mp;
    rep(i,m){
        int b;
        cin >> b;
        mp[b]++;
    }
    int x;
    cin >> x;
    vector<int> dp(300000);
    dp[0] = 1;
    rep(i,100001){
        rep(j,n){
            if(dp[i] && mp.count(i) == 0){
                dp[a[j] + i] = 1;
            }
        }
    }
    if(dp[x] == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
