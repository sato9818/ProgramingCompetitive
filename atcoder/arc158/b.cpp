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
    vector<int> minus, plus;
    rep(i,n) {
        int x;
        cin >> x;
        if(x < 0) minus.push_back(x);
        else plus.push_back(x);
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end());

    // for(auto x : minus) cout << x << " ";
    // cout << endl;
    // for(auto x : plus) cout << x << " ";
    // cout << endl;

    vector<double> cand;
    int plus_n = plus.size();
    int minus_n = minus.size();
    rep(i,3){
        if(i < minus_n / 2) cand.push_back(minus[i]);
        if(plus_n-i-1 >= plus_n / 2) cand.push_back(plus[plus_n-i-1]);
        if(i < plus_n / 2) cand.push_back(plus[i]);
        if(minus_n-i-1 >= minus_n /2) cand.push_back(minus[minus_n-i-1]);
    }

    

    double min_ans = 10000000;
    double max_ans = -10000000;
    rep(i,cand.size()){
        for(int j = i+1; j < cand.size(); j++){
            for(int k = j+1; k < cand.size(); k++){
                double ans = (double)(cand[i] + cand[j] + cand[k]) / (cand[i] * cand[j] * cand[k]);
                // cout << cand[i] << " " << cand[j] << " " << cand[k] << " " << ans << endl;
                min_ans = min(min_ans, ans);
                max_ans = max(max_ans, ans);
            }
        }
    }

    // rep(i,max_cand.size()){
    //     for(int j = i+1; j < max_cand.size(); j++){
    //         for(int k = j+1; k < max_cand.size(); k++){
    //             double ans = (double)(max_cand[i] + max_cand[j] + max_cand[k]) / (max_cand[i] * max_cand[j] * max_cand[k]);
    //             // cout <<max_cand[i] << " " <<  max_cand[j] << " " <<max_cand[k] << " " << ans << endl;
    //             min_ans = min(min_ans, ans);
    //             max_ans = max(max_ans, ans);
    //         }
    //     }
    // }

    cout << fixed << setprecision(12) << min_ans << endl;
    cout << fixed << setprecision(12) << max_ans << endl;


    return 0;
}
