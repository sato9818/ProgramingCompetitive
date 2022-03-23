#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, string>;

const int MOD = 998244353;
const int INF = 1001001001;

int main() {
    int t;
    cin >> t;
    rep(i,t) {
        int n;
        string s;
        cin >> n >> s;
        ll sum = 0;
        ll base = 1;
        for(int j=(n-1)/2;j>=0;j--){
            sum = (sum + base * (s[j] - 'A')) % MOD;
            base = (base * 26) % MOD;
        }
        int flag = 0;
        for(int j=(n-1)/2;j>=0;j--){
            if(s[j] > s[n-1-j]){
                flag = 1;
                break;
            } else if(s[j] < s[n-1-j]) {
                sum = (sum + 1) % MOD;
                flag = 1;
                break;
            }
        }
        if(!flag){
            sum = (sum + 1) % MOD;
        }
        cout << sum << endl;
        
    }
    return 0;
}
