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
    map<int, ll> m;
    rep(i,n) {
        int a; 
        cin >> a;
        m[i] = a;
    }

    int q;
    ll init = -1;
    cin >> q;
    rep(i,q){
        int t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            init = x;
            m.clear();
        }else if(t == 2){
            int index;
            ll x;
            cin >> index >> x;
            if(m.count(index-1) > 0){
                m[index-1] += x;
            }else{
                m[index-1] = init + x;
            }
        }else if(t == 3){
            int index;
            cin >> index;
            if(m.count(index-1) > 0){
                cout << m[index-1] << endl;
            }else{
                cout << init << endl;
            }
        }
    }

    return 0;
}
