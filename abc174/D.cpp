#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int w = 0, r = 0;
    rep(i,n){
        if(s[i] == 'W'){
            w++;
        }else if(s[i] == 'R'){
            r++;
        }
    }
    if(w == 0 || r == 0){
        cout << 0 << endl;
        return 0;
    }
    rep(i,r){
        if(s[i] == 'W'){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}