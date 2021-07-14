#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,x;

  cin >> n >> x;
  int sum = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(i % 2 == 0){
      sum += a;
    }else{
      sum += a - 1;
    }
  }

  if(sum > x){
    cout << "No" << endl;

  }else{
    cout << "Yes" << endl;
  }
  
  return 0;
}