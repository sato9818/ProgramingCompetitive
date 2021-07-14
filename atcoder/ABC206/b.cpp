#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;
  
  ll sum = 0;
  int i = 1;
  while(sum < n){
    sum += i;
    i++;
  }
  cout << i-1 << endl;
  return 0;
}