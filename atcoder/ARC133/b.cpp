#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    map<int,int> m;
    rep(i,n) cin >> p[i];
    rep(i,n){
        int q;
        cin >> q;
        m[q] = i;
    }

    vector<P> pr;
    rep(i,n){
        for(int j=p[i];j<n+1;j+=p[i]){
            pr.emplace_back(i,m[j]);
        }
    }
    
    sort(pr.begin(),pr.end(), [](P a, P b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    // rep(i,pr.size()){
    //     cout << pr[i].first << ":" << pr[i].second << endl;
    // }

    vector<int> dp(n, INF);
    rep(i,pr.size()){
        int ind = lower_bound(dp.begin(), dp.end(), pr[i].second) - dp.begin();
        dp[ind] = pr[i].second;
    }

    rep(i,n){
        if(dp[i] == INF){
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;
    return 0;
}
