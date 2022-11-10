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
    ll a,b,n;
    cin >> n >> a >> b;
    ll sum = n * (n+1) / 2;
    if(a == 1 || b == 1){
        cout << 0 << endl;
    }else{
        ll na = n / a, nb = n / b;
        sum -= na * (2*a + (na - 1) * a) / 2;
        sum -= nb * (2*b + (nb - 1) * b) / 2;
        ll ab = lcm(a,b);
        ll nab = n / ab;
        sum += (ll)nab * (2*ab + (nab - 1) * ab) / 2;
        cout << sum << endl;
    }
    return 0;
}
