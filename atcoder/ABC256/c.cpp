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
    int h1,h2,h3,w1,w2,w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    int ans = 0;

    rep1(i1,30){
        rep1(i2,30){
            rep1(j1,30){
                rep1(j2,30){
                    if(i1 + i2 >= h1){
                        continue;
                    }
                    if(j1 + j2 >= h2){
                        continue;
                    }
                    if(i1 + j1 >= w1){
                        continue;
                    }
                    if(i2 + j2 >= w2){
                        continue;
                    }
                    int i3 = h1 - i1 - i2;
                    int j3 = h2 - j1 - j2;
                    int k1 = w1 - i1 - j1;
                    int k2 = w2 - i2 - j2;
                    if(w3 - i3 - j3 != h3 - k1 - k2 || h3 - k1 - k2 <= 0){
                        continue;
                    }
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
