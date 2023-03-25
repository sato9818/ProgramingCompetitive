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
    vector<int> x(5*n);
    rep(i,5*n){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    int sum = 0;
    rep(i,3*n){
        sum += x[n+i];
    }
    cout << (double)sum / (3*n) << endl;

    return 0;
}
