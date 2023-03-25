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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> sets(m);
    rep(i,m){
        int c;
        cin >> c;
        rep(j,c){
            int a;
            cin >> a;
            sets[i].push_back(a);
        }
    }


    ll ans = 0;

    rep(i, 1<<m){
        
        set<int> s;
        rep(j,m){
            if(1 & (i>>j)){
                for(auto num : sets[j]){
                    s.insert(num);
                }
            }
        }
        if(s.size() == n){
            ans++;
        }
    }
    cout << ans <<endl;

    return 0;
}
