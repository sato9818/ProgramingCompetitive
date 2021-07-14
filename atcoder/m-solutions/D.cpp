#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n+1);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll money = 1000;
    ll mx = 0;
    ll stock = 0;
    rep(i,n){
        cin >> a[i];
    }
    
    for(int i=0;i<n-1;i++){
        if(a[i] > a[i+1]){
            money += a[i] * stock;
            stock=0;
            
        }else if(a[i] < a[i+1]){
            stock += money / a[i];
            money %= a[i];
        }
        mx = max(mx,money); 
        // cout << money << endl;
    }
    money += a[n-1] * stock;
    stock=0;
    mx = max(mx,money); 
    cout << mx << endl;
   	
  	
    
    
    return 0;
}