#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    for(ll i = 1;i<n+1;i ++){
        ll sum = i * (i-1) / 2;
        if((n - sum) < i){
            break;
        }
        if((n - sum) % i == 0){
            ans ++;
        }
    }
    cout << ans * 2 << endl;
    return 0;
}