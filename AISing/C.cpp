#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n+1);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    
    rep1(x,n){
        
        rep1(y,n){

            rep1(z,n){
                ll ans = x*x + y*y + z*z + x*y + y*z + z*x;
                if(ans > n){
                    break;
                }
                a[ans]++;
            }
        }
    }
    rep1(i,n){
        cout << a[i] << endl;
    }
   	
  	
    
    
    return 0;
}