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
    int n, q;
    cin >> n >> q;

    map<int,int> mp;

    rep(i,q){
        int t,x;
        cin >> t >> x;
        if(t == 1){
            mp[x]++;
        }else if(t == 2){
            mp[x] += 2;
        }else{
            if(mp[x] > 1){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
