#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 素数列挙
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

// 素因数分解
vector<int> factors(int n, const vector<int>& min_factor) {
  // min_factor は sieve() で得られたものとする
  vector<int> res;
  while (n > 1) {
    res.push_back(min_factor[n]);
    n /= min_factor[n];
    // 割った後の値についても素因数を知っているので順次求まる
  }
  return res;
}

// 素因数分解
map<int, int> factor_count(int n, const vector<int>& min_factor) {
  // min_factor は sieve() で得られたものとする
  map<int, int> factor_count;
  while (n > 1) {
    factor_count[min_factor[n]]++;
    n /= min_factor[n];
    // 割った後の値についても素因数を知っているので順次求まる
  }
  return factor_count;
}

int main(void){
  int n;
  cin >> n;
  vector<int> prime = sieve(n);

  rep(i,prime.size()){
    cout << prime[i] << endl;
  }
  

  return 0;
}