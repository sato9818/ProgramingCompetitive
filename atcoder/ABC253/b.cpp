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
    int h, w;
    cin >> h >> w;
    int x = -1, y = -1;
    int ans;
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            if(s[j] == 'o'){
                if(x == -1 && y == -1){
                    x = i;
                    y = j;
                }else{
                    ans = abs(x-i) + abs(y-j);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
