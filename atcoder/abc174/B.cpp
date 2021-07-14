#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    ll D;

    cin >> N >> D;
    D = D*D;
    int cnt = 0;
    rep(i,N){
        ll x,y;
        cin >> x >> y;
        ll dis = x*x + y*y;
        if(dis <= D){
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}