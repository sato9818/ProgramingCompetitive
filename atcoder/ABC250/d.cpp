#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

vector<int> sieve(int n){
  vector<int> prime;
  vector<int> is_prime(n+1,0);
  is_prime[0] = is_prime[1] = 1;
  for(int i=2;i<n+1;i++){
    if(is_prime[i] == 0){
      prime.push_back(i);
      for(int j=2*i;j<n+1;j+=i){
        if(is_prime[j] == 0){
          is_prime[j] = 1;
        }
      }
    }
  }
  return prime;
}

int main() {
    ll n;
    cin >> n;
    vector<int> prime = sieve(1000000);
    
    ll ans = 0;
    for(auto x : prime){
        int p = min(n / ((ll)x*x*x), (ll)x-1);
        int dis = lower_bound(prime.begin(), prime.end(), p) - prime.begin();
        if(prime[dis] == p){
            ans += dis + 1;
        }else{
            ans += dis;
        }
        
    }

    // n = 16
    // 2 3 5 7 11
    // 

    cout << ans << endl;

    return 0;
}
