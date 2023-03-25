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
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    vector<double> xd;
    rep(i,n) {
        xd.push_back(1.0/x[i]);
    }
    sort(xd.begin(), xd.end());

    vector<double> cands;

    rep(i,3){
        if(i < n/2) cands.push_back(xd[i]);
        if(n-i-1 >= n/2) cands.push_back(xd[n-i-1]);
    }

    double max_ans = -1000000, min_ans = 1000000;

    rep(i,cands.size()) {
        for(int j = i+1;j<cands.size();j++){
            for(int k=j+1;k<cands.size();k++){
                double ans = cands[i] * cands[j] + cands[j] * cands[k] + cands[k] * cands[i];
                max_ans = max(max_ans, ans);
                min_ans = min(min_ans, ans);
            }
        }
    }
    cout << fixed << setprecision(12) << min_ans << endl;
    cout << fixed << setprecision(12) << max_ans << endl;


    return 0;
}
