#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    int cmax0 = -2001001001;
    int cmin0 = 2001001001;
    int cmax1 = -2001001001;
    int cmin1 = 2001001001;
    
    rep(i,n){
        int x,y;
        cin >> x >> y;
        cmax0 = max(x-y, cmax0);
        cmin0 = min(x-y, cmin0);
        cmax1 = max(x+y, cmax1);
        cmin1 = min(x+y, cmin1);
    }

    cout << max(cmax0 - cmin0, cmax1 - cmin1) << endl;
    return 0;
}