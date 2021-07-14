// c++ version (Homebrew GCC 11.1.0_1) 11.1.0

#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector<int> sieve(int n){
  vector<int> prime;
  vector<bool> is_prime(n+1,0);
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

int fetch_small_factor(int n, const vector<int>& primes) {
  int small_factor = 1;
  rep(i,primes.size()){
    int prime = primes[i];
    if(n % prime == 0){
      small_factor = prime;
      break;
    }
  }
  return small_factor;
}

int main() {
  const char words[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '.', ',', '-', '!', '?'};
  const int MOD = 41;
  const int MAX_DEFAULT = 50;
  const int MAX_STEP = 10;

  string s;
  cin >> s;

  vector<int> numbers;
  int max_number = 0;

  stringstream ss(s);
  string buf;
  while (getline(ss, buf, ':')) {
    int num = stoi(buf);
    numbers.push_back(num);
    max_number = max(max_number, num);
  }
  
  // 工夫点
  // 存在する最も大きい数の1/2乗以下の素数をあらかじめ列挙した。
  vector<int> primes = sieve(sqrt(max_number));
  vector<int> small_primes;
  rep(i,numbers.size()){
    small_primes.push_back(fetch_small_factor(numbers[i], primes));
  }
  
  rep(def,MAX_DEFAULT){
    rep(step,MAX_STEP){
      string ans = "";
      int s_cnt = 0;
      int o_cnt = 0;
      rep(i,numbers.size()){
        int key = ((small_primes[i] - def - step * i) % MOD + MOD) % MOD;
        char word = words[key];
        ans += word;
        if(word == 's'){
          s_cnt++;
        }
        if(word == 'o'){
          o_cnt++;
        }
      }
      if(s_cnt == 4 && o_cnt == 6){
        cout << "default: " << def << endl;
        cout << "step: " << step << endl;
        cout << ans << endl;
      }
    } 
  }

  return 0;
}