#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  cin >> n;

  double sum = 0;
  rep1(i,n){
    sum += (double)n / (n-i);
  }

  printf("%f\n", sum);
  
  return 0;
}
