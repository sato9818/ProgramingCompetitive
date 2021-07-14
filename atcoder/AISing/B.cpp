#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    
    int ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        if((i+1) % 2 == 1 && a % 2 == 1){
            ans++;
        }
    }
    
   	
  	
    cout << ans << endl;
    
    return 0;
}