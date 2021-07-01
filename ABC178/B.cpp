#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll mx = -1001001001001001001;
   	mx = max(mx, a*d);
    mx = max(mx, b*c);
    mx = max(mx, a*c);
    mx = max(mx, b*d);
    cout << mx << endl;
    return 0;
}