#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n;
    cin >> n;
    vector<P> range(n);
    rep(i,n){
        int l,r;
        cin >> l >> r;
        range[i] = P(l,r);
    }

    sort(range.begin(), range.end());

    vector<P> ans;
    int l = range[0].first, r = range[0].second;

    rep1(i,n){
        int curl = range[i].first, curr = range[i].second;
        if(curl > r){
            ans.emplace_back(l,r);
            l = curl;
            r = curr;
        }else{
            r = max(curr, r);
        }
    }
    ans.emplace_back(l,r);
    rep(i,ans.size()){
        cout << ans[i].first << " " << ans[i].second << endl;
    }


    return 0;
}
