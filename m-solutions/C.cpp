#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n+1);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    
    for(int i=k;i<n;i++){
        if(a[i] > a[i-k]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
   	
  	
    
    
    return 0;
}