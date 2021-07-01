#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n+1);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int n;
    string x;
    cin >> n;
    cin >> x;

    rep(i,n){
        string str = x;
        // ll s = sum;
        if(x[i] == '1'){
            str[i] = '0';
        }else{
            str[i] = '1';
        }
        bitset<200005> sum(str);
        int ans = 0;
        while(sum != 0){
            // bitset<200005> b(s);
            sum = sum << sum.count();
            ans ++;
        }


        // mul /= 2;
        cout << ans << endl;
    }
    
   	
  	
    
    
    return 0;
}