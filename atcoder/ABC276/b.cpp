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
    vector<vector<int>> v(n);

    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    rep(i,n){
        sort(v[i].begin(), v[i].end());
        cout << v[i].size() << " ";
        for(auto city:v[i]){
            cout << city + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
