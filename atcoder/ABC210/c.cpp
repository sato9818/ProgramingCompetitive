#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> c(n);

  map<int,int> m;

  rep(i,n){
    cin >> c[i];
  }

  rep(i,k){
    m[c[i]]++;
  }
  int size = m.size();
  int ans = m.size();
  for(int i=k;i<n;i++){
    m[c[i-k]]--;
    if(m[c[i-k]] == 0){
      size --;
    }
    m[c[i]]++;
    if(m[c[i]] == 1){
      size++;
    }
    ans = max(ans, size);
  }

  cout << ans << endl;
  
  return 0;
}
