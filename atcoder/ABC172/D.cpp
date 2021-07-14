#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main(void){
    int n;
    cin >> n;
    //0だと素数
    vector<ll> is_prime(n+1,0);
    
    is_prime[0] = is_prime[1] = 1;
    for(int i=2;i<n+1;i++){
        // is_prime[i]++;
        if(is_prime[i] == 0){
            is_prime[i] = 1;
            int cnt = 2;
            for(int j=2*i;j<n+1;j+=i){
                // cnt = j / i;
                is_prime[j] += is_prime[i] + is_prime[cnt];
                cnt++;
            }
        }
    }

    ll sum = 0;
    for(int i=2;i<is_prime.size();i++){
        // cout << is_prime[i] << endl;
        sum += i * (is_prime[i] + 1);
    }
    sum ++;
    cout << sum << endl;
    return 0;
}