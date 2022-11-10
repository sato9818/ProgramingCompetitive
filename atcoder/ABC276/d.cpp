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
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }

    int cnt = 0;
    int exist = 1;
    while(exist) {
        int change = 1;
        exist = 0;
        rep(i,n){
            if(a[i] % 2 == 0){
                cnt++;
                a[i] /= 2;
                exist = 1;
            }else{
                change = 0;
            }
        }
        if(change) cnt -= n;
    }
    exist = 1;
    while(exist) {
        int change = 1;
        exist = 0;
        rep(i,n){
            if(a[i] % 3 == 0){
                cnt++;
                a[i] /= 3;
                exist = 1;
            }else{
                change = 0;
            }
        }
        if(change) cnt -= n;
    }

    int same = 1;

    // rep(i,n)cout << a[i] << endl;

    rep1(i,n){
        if(a[i-1] != a[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;

    return 0;
}
