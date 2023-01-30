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
    int m;
    double eps;
    cin >> m >> eps;
    const int N = 100;

    cout << N << endl;

    int v = N*(N-1)/2;

    vector<string> gs(m), hs(m, "");


    rep(k,m){
        string g = "";
        rep(i,k*v/(m-1)){
            g.push_back('1');
        }
        rep(j,v - k*v/(m-1)){
            g.push_back('0');
        }
        cout << g << endl;
        gs[k] = g;
    }

    mt19937 rand_src(15843122);
    uniform_int_distribution<int> rand_dist(0, 99);

    rep(k,m) {
        rep(i,v){
            if(rand_dist(rand_src) < (int)(eps * 100)){
                if(gs[k][i] == '1')  hs[k].push_back('0');
                else hs[k].push_back('1');
            }else{
                hs[k].push_back(gs[k][i]);
            }
        }
    }

    // rep(k,m){
    //     cout << hs[k] << endl;
    // }

    vector<int> expected_v(m);
    rep(k,m){
        expected_v[k] = round(k*v/(m-1) * (1 - eps) + (v - k*v/(m-1)) * eps);
        // cout << expected_v[k] << endl;
    }

    rep(q,100){
        int index;
        cin >> index;
        string h = hs[index];

        // string h;
        // cin >> h;

        int cnt = 0;
        rep(i,v){
            if(h[i] == '1'){
                cnt++;
            }
        }

        int pos = lower_bound(expected_v.begin(), expected_v.end(), cnt) - expected_v.begin();
        if(pos == m) {
            pos = m-1;
        }else if(pos > 0){
            if(abs(expected_v[pos-1] - cnt) < abs(expected_v[pos] - cnt)){
                pos--;
            }
        }

        cout << pos << endl;
    }

    return 0;
}
