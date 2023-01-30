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
    int n,q;
    cin >> n >> q;

    map<int,set<int>> follows;

    rep(i,q){
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1){
            follows[a].insert(b);
        }else if(t == 2){
            follows[a].erase(b);
        }else if(t == 3){
            if(follows[a].find(b) != follows[a].end() && follows[b].find(a) != follows[b].end()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}
