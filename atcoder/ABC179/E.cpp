#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 998244353;

int pow_kai(int a, int n){//aのn乗を計算します。
  int x = 1;
  while(n > 0){//全てのbitが捨てられるまで。
    if(n&1){//1番右のbitが1のとき。
      x %= MOD;
      x = x*a;
    }
    a = a*a;
    n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
  }
  return x;
}

int S2(int a, int n){
    return (a * pow_kai(2, n) - a);
}

int main() {
    int N, X, M;
    cin >> N >> X >> M;
    ll sum = 0;
    cout << sum << endl;
    return 0;
}