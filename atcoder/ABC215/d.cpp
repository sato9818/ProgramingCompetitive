#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector<int> sieve(int n){
  vector<int> is_prime(n+1,0);
  for(int i=2;i<n+1;i++){
    if(is_prime[i] == 0){
      is_prime[i] = i;
      for(int j=2*i;j<n+1;j+=i){
        if(is_prime[j] == 0){
          is_prime[j] = i;
        }
      }
    }
  }
  return is_prime;
}

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

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(n);

  
  rep(i,n){
    cin >> a[i];
  }

  vector<int> prime = sieve(100000+1);
  

  vector<int> is_ok(m+1,0);
  vector<int> visited(100000+1,0);
  is_ok[0] = is_ok[1] = 1;
  rep(i,n){
    vector<int> facs = factors(a[i], prime);
    rep(k,facs.size()){
      if(visited[facs[k]]) continue;
      visited[facs[k]] = 1;
      for(int j = facs[k];j<m+1;j += facs[k]){
        if(!is_ok[j]){
          is_ok[j] = 1;
        }
      }
    }
    
  }
  vector<int> ans;
  ans.push_back(1);

  rep1(i,m+1){
    if(!is_ok[i]){
      ans.push_back(i);
    }
  }
  
  cout << ans.size() << endl;
  rep(i,ans.size()){
    cout << ans[i] << endl;
  }

  return 0;
}
