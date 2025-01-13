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
    vector<int> e(n);
    rep(i,n){
        int a;
        cin >> a;
        a--;
        e[i] = a;
    }

    vector<int> visited(n,0), visited2(n,0);
    int now = 0;
    while(!visited[now]){
        visited[now] = 1;
        now = e[now];
    }

    vector<int> ans;
    while(!visited2[now]){
        ans.push_back(now);
        visited2[now] = 1;
        now = e[now];
    }

    cout << ans.size() << endl;
    for(auto v : ans) {
        cout << v+1 << endl;
    }



    

    return 0;
}
