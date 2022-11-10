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
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;

    // if(l1 < l2){
    //     cout << max(0, r1-l2) << endl;
    // }else if(l2 < l1){
    //     cout << max(0, r2-l1) << endl;
    // }else{
    //     cout << min(r1, r2) - l1 << endl;
    // }
    cout << max(min(r1, r2) - max(l1, l2), 0) << endl;

    return 0;
}
