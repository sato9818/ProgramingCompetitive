#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int N = 1048576;

int main() {
  int q;
  cin >> q;

  vector<ll> v(N,-1);
  vector<int> cnt(N,0);

  rep(i, q) {
    int t;
    ll x;
    cin >> t >> x;
    if(t == 1){
      int idx = x % N;
      if(v[idx] == -1){
        v[idx] = x;
        cnt[idx]++;
      }else{
        int idx2 = idx;
        while(v[idx2] != -1){
          int idx3 = (idx2 + cnt[idx2]) % N;
          cnt[idx2]++;
          idx2 = idx3;
        }
        v[idx2] = x;
        cnt[idx2]++;
      }
    }else if(t == 2){
      cout << v[x % N] << endl;
    }
  }
  return 0;
}
