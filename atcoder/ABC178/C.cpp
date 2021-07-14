#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int A = 1000000007;
    ll sum10 = 1;
    ll sum9 = 1;
    ll sum8 = 1;
   	rep(i,n){
        sum10 = (sum10 % A) * 10;  
        sum9 = (sum9 % A) * 9; 
        sum8 = (sum8 % A) * 8;
    }
    ll ans = (sum10 - sum8) - 2 * (sum9 - sum8);
    ans = ans % A;
    if(ans < 0) ans += A;
    cout << ans << endl;
    return 0;
}