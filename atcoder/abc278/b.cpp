#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool is_misunderstood(int h, int m) {
    int nm, nh;
    nm = h % 10 * 10 + m % 10;
    h /= 10; m /= 10;
    nh = h % 10 * 10 + m % 10;
    if(0 <= nh && nh <= 23 && 0<= nm && nm <= 59) return true;
    else return false;
}

int main() {
    int h, m;

    cin >> h >> m;
 
    while(!is_misunderstood(h, m)){
        m++;
        if(m == 60){
            m = 0;
            h++;
            if(h == 24) h = 0;
        }
    }
    cout << h << " " << m << endl;    

    return 0;
}
