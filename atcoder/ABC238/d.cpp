#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

int main() {
    int t;
    cin >> t;
    rep(i,t){
        ll a,s;
        cin >> a >> s;
        ll num = 1;
        s -= a*2;
        if(s < 0){
            cout << "No" << endl;
            continue;
        }
        rep(j,59){
            num *= 2;
        }
        rep(j,60){
            if(!((a>>(60-j-1)) & 1)){
                if(num <= s){
                    s -= num;
                }
            }
            num /= 2;
        }
        // cout << s << endl;
        if(s == 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
  
    return 0;
}
