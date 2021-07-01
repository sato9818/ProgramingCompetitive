#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int k;
    cin >> k;
    map<int,int> m;
    int d = 7;
    int x = 7;
    ll cnt = 1;
    while(true){
        x %= k;
        if(m[x] > 0){
            cout << -1 << endl;
            return 0;
        }
        m[x]++;
        if(x == 0){
            cout << cnt << endl;
            return 0;
        }
        x = x*10 + 7;
        cnt++;
        
        // cout << x << endl;
    }

    
    return 0;
}