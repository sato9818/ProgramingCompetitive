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

    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
    }

    map<int,int> turn;
    int mx = 0;

    rep(i,n){
        int dish = p[i];
        turn[(p[i]-i+n) % n]++;
        turn[(p[i]-i+n+1) % n]++;
        turn[(p[i]-i+n-1) % n]++;
        mx = max(mx, max(turn[(p[i]-i+n) % n], max(turn[(p[i]-i+n+1) % n], turn[(p[i]-i+n-1) % n])));
    }

    cout << mx << endl;

    return 0;
}
