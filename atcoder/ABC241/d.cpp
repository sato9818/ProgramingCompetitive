#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

int main() {
    int q;
    cin >> q;
    multiset<ll> ms;

    rep(i,q){
        ll c, x, k;
        cin >> c;
        int flag = 0;
        if(c == 1){
            cin >> x;
            ms.insert(x);
        }else if(c == 2){
            cin >> x >> k;
            k--;
            auto itr = ms.upper_bound(x);
            if(itr == ms.begin()){
                cout << -1 << endl;
                continue;
            }
            itr--;
            rep(i,k){
                if(itr == ms.begin()){
                    flag = 1;
                    break;
                }
                itr--;
            }
            if(flag){
                cout << -1 << endl;
            }else{
                cout << *itr << endl;
            }
        }else if(c == 3){
            cin >> x >> k;
            k--;
            auto itr = ms.lower_bound(x);
            if(itr == ms.end()){
                cout << -1 << endl;
                continue;
            }
            rep(i,k){
                itr++;
                if(itr == ms.end()){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << -1 << endl;
            }else{
                cout << *itr << endl;
            }
        }
    }
  
    return 0;
}
