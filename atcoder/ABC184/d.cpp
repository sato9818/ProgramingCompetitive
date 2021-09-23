#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

double dp[105][105][105] = {0};

double rec(int a, int b, int c){
  double sum = 0;
  if(dp[a][b][c] != 0){
    return dp[a][b][c];
  }
  if(a == 100 || b == 100 || c == 100){
    return 0;
  }
  sum += (1+rec(a+1,b,c)) * a / (a+b+c);
  sum += (1+rec(a,b+1,c)) * b / (a+b+c);
  sum += (1+rec(a,b,c+1)) * c / (a+b+c);
  return dp[a][b][c] = sum;
}

int main() {
  int a,b,c;
  cin >> a >> b >> c;

  cout << fixed << setprecision(10);
  cout << rec(a,b,c) << endl;

  
  return 0;
}
