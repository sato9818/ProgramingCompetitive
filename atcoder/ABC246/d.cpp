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
    ll n;
    cin >> n;
    int a = 0;
    int b = 0;
    for(ll i=0;i<1000001;i++){
        if(i * i * i * 4 >= n){
            a = i;
            b = i;
            break;
        }
    }
    ll ans = LINF;
    ll j = 1000000;
    for(ll i=0;i<=a;i++){
        while(true){
            ll sum = i * i * i + i * i * j + i * j * j + j * j * j;
            if(j<i){
                break;
            }
            if(sum >= n){
                ans = min(ans, sum);
                j--;
            }else{
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
