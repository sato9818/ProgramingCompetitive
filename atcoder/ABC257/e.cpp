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
    vector<int> costs(9);
    vector<string> dp(n+1, "");

    rep(i,9){
        cin >> costs[i];
    }
    int digits = 0;
    int min_cost = INF;
    rep(i,9){
        digits = max(digits, n/costs[i]);
        min_cost = min(min_cost, costs[i]);
    }
    string ans = "";

    rep(i,digits){
        rep(j,9){
            if((n-costs[8-j]) >= (digits-i-1) * min_cost){
                ans.push_back('0' + (9-j));
                n -= costs[8-j];
                break;
            }
        }
    }
    
    if(ans == "") cout << 0 << endl;
    cout << ans << endl;
    return 0;
}
