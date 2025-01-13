#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool more_than(vector<int>& a, vector<int>& b, int tar){
    int an = 0;
    int bn = 0;
    rep(i,a.size()){
        if(a[i] <= tar) an++;
    }
    rep(i,b.size()){
        if(b[b.size()-1 - i] >= tar) bn++;
    }
    return an >= bn;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = -1, r = INF;
    int ans = 0;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(more_than(a,b,mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}
