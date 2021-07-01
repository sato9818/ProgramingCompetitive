#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector<int> sieve(int n){
  vector<int> prime;
  vector<int> is_prime(n+1,0);
  for(int i=2;i<n+1;i++){
    if(is_prime[i] == 0){
      is_prime[i] = i;
      prime.push_back(i);
      for(int j=2*i;j<n+1;j+=i){
        if(is_prime[j] == 0){
          is_prime[j] = i;
        }
      }
    }
  }
  return is_prime;
}

map<int, int> factor_count(int n, const vector<int>& min_factor) {
  // min_factor は sieve() で得られたものとする
  map<int, int> factor_count;
  while (n > 1) {
    factor_count[min_factor[n]]++;
    n /= min_factor[n];
  }
  return factor_count;
}

const int MAX = 500005;
const int MOD = 998244353;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main() {
  int n, m;
  cin >> n >> m;
  
  COMinit();
  vector<int> is_prime = sieve(m);
  
  ll ans = 0;

  for(int i=2;i<m+1;i++){
    ll sum = 1;
    map<int, int> mp = factor_count(i, is_prime);
    for(auto x : mp){
      sum *= COM(x.second + n-1, x.second);
      sum %= MOD;
    }
    ans += sum;
    ans %= MOD;
  }

  cout << ans + 1 << endl;
  return 0;
}