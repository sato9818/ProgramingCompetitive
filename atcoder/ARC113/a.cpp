#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;
  int sum =0;
  for(int i=1;i<k+1;i++){
    int mul1 = 6;
    int mul2 = 3;
    for(int j=i;j<sqrt(k+1);j++){
      if(i == j){
        mul1 = 3;
        mul2 = 1;
      }else{
        mul1 = 6;
        mul2 = 3;
      }
      int cnt = (k / i / j - j);
      if(cnt >= 0){
        sum += cnt * mul1 + mul2;
      }
      // cout << "i: " << i << "j: " << j << "cnt: " << cnt << endl;
      
    }
  }
  cout << sum << endl;
  return 0;
}