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
    ll s = 1;
    vector<vector<ll>> memo(1000005,vector<ll>(10,0));
    rep(i,10){
        memo[1][i] = i;
    }
    rep1(i,1000000) {
        rep(j,10) {
            memo[i+1][j] = memo[i][j] * 10 % MOD;
        }
    }
    int q;
    cin >> q;
    queue<int> que;
    que.push(1);
    rep(i,q){
        int t;
        cin >> t;
        
        if(t == 1) {
            int x;
            cin >> x;
            s = s*10 + x;
            s %= MOD;
            que.push(x);
        }else if(t == 2){
            int n = que.size();
            int head = que.front(); que.pop();
            while(!que.empty() && que.front() == 0){
                que.pop();
            }
            // cout << "s:" << s << endl;
            // cout << "memo[n][head]:" << memo[n][head] << endl;
            // cout << "n:" << n << " head:" << head << endl;
            s -= memo[n][head];
            s = (s + MOD) % MOD;
            // cout << "s:" << s << endl;
        } else {
            cout << s << endl;
        }

    } 

    return 0;
}
