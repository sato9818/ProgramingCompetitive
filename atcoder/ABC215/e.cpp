#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<ll> cnt(10,0);
  vector<int> visited(10,0);

  map<char,int> cton;

  char c = 'A';
  rep(i,10){
    cton[c] = i;
    c++; 
  }

  ll sum = 1;

  rep(i,n){
    
    sum = (sum * 2);

    if(visited[cton[s[i]]]){
      sum -= (cnt[cton[s[i]]]-1);
    }else{
      visited[cton[s[i]]] = 1;
    }
    cnt[cton[s[i]]] = 1;
    
    rep(j,10){
      if(visited[j]){
        if(cton[s[i]] != j){
          cnt[j] = (cnt[j] * 2) % MOD;
        }
      }
    }
    sum %= MOD;

  }

  // rep(i,10){
  //   cout << cnt[i] << endl;
  // }

  cout << (sum - 1 + MOD) % MOD << endl;

  
  return 0;
}
