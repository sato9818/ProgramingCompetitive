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
    int q;
    cin >> q;

    map<int,int> m;

    rep(i,q){
        int num;
        cin >> num;
        if(num == 1){
            int x;
            cin >> x;
            m[x]++;
        }else if(num == 2){
            int x,c;
            cin >> x >> c;
            if(m[x] <= c){
                m.erase(x);
            }else{
                m[x] -= c;
            }
        }else if(num == 3){
            auto [k1,v1] = *m.begin();
            auto [k2,v2] = *m.rbegin();
            cout << k2 - k1 << endl;
        }
    }

    return 0;
}
