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
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;

    map<P,int> items;

    rep(i,m){
        int x,y;
        cin >> x >> y;
        items[P(x,y)] = 1;
    }
    
    int x = 0, y = 0;

    for(auto ch : s) {
        h--;
        if(ch == 'R'){
            x++;
        }else if(ch == 'L'){
            x--;
        }else if(ch == 'U'){
            y++;
        }else if(ch == 'D'){
            y--;
        }
        if(h < 0) {
            cout << "No" << endl;
            return 0;
        }
        if(h < k && items.count(P(x,y)) > 0) {
            h = k;
            items.erase(P(x,y));
        }
    }
    cout << "Yes" << endl;
    return 0;
}
