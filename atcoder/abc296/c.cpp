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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    map<int,int> mp;
    rep(i,n) {
        mp[a[i]]++;
    }
    rep(i,n) {
        if(mp.count(a[i] - x) != 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
