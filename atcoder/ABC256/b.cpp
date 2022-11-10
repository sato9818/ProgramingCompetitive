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
    vector<int> a(n,0);
    int ans = 0;
    rep(i,n){
        int x;
        cin >> x;
        rep(j,i+1){
            if(a[j] > 3){
                continue;
            }
            a[j] += x;
            if(a[j] > 3){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
