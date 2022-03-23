#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, ll> m,cnt;
    rep(i,n){
        cin >> a[i];
    }
    int rem = 0;
    ll sum = 0;

    auto add_sum = [&](){
        sum += a[rem];
        rem = sum % n;
    };

    rep(i,k){
        add_sum();
        if(m[rem] > 0){
            ll loop = i - cnt[rem];
            sum += (sum - m[rem]) * ((k - i - 1)/loop);
            // cout << (k - i - 1) << endl;
            // cout << (k - i - 1)/loop << endl;
            // cout << (k - i - 1)%loop << endl;
            rep(j,(k - i - 1)%loop){
                add_sum();
            }
            break;
        }else{
            m[rem] = sum;
            cnt[rem] = i;
        }
    }
    cout << sum << endl;
    
    return 0;
}
