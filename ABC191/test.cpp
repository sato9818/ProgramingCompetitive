#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  map<int,int> mp;
  int l = 1e9;
  auto add = [&](int a, int x){
    int p = mp[x];
    cout << p << endl;
    mp[x] = gcd(a,p);
    cout << mp[x] << endl;
  };
  for(int j = 1;j*j<= 6;j++){
    if(6 % j == 0){
      add(6,j);
      add(6,6/j);
    } 
    l = min(l,6);
  }
  
  return 0;
}