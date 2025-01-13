#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int mex(vector<int>& a) {
    int mex = 0;
    sort(a.begin(), a.end());
    rep(i,3){
        if(mex == a[i]) mex++;
        else return mex;
    }
    return mex;
}

ll get_mex(vector<ll>& ms, vector<ll>& xs, int e) {
    ll sum = 0;
    rep(i,3){
        rep(j,3){
            vector<int> a = {i, j, e};
            ll m = ((ll)mex(a) * ms[i] * xs[j]);
            sum += m;
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string str;
    cin >> str;

    vector<vector<ll>> ms(n, vector<ll>(3,0)), xs(n, vector<ll>(3,0));

    rep(i,n){
        if(str[i] == 'M') {
            ms[i][a[i]]++;
        }
        if(str[n-1-i] == 'X') {
            xs[n-1-i][a[n-1-i]]++;
        }
    }

    rep1(i,n) {
        rep(j,3){
            ms[i][j] += ms[i-1][j];
            xs[n-1-i][j] += xs[n-i][j];
        }
    }

    ll ans = 0;
    rep(i,n){
        if(str[i] == 'E') {
            ans += get_mex(ms[i], xs[i], a[i]);
        }
    }



    cout << ans << endl;

    return 0;
}
