#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 1000000007;

int main() {
  string s;
  cin >> s;
  vector<char> chokudai{'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};
  map<char, ll> m;
  rep(i,s.size()){
    if(s[i] == 'c'){
      m['c']++;
    }
    rep1(j,chokudai.size()){
      if(s[i] == chokudai[j]){
        m[chokudai[j]] = (m[chokudai[j]] + m[chokudai[j-1]]) % MOD;
      }
    }
  }

  cout << m['i'] << endl;
  
  return 0;
}
