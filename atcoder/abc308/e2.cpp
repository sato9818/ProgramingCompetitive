#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<=(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int mex(vector<int>& a) {
    sort(a.begin(), a.end());
    rep(i,3){
        if(i == a[i]) continue;
        else return i;
    }
    return 3;
}

int main() {
    vector<int> a = {1,0,0};
    cout << mex(a) << endl;
    

    return 0;
}
