#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

vector<vector<ll> > d;

const ll INF = 1001001001001001001;

ll warshall_floyd(int n) { // nは頂点数
  ll sum = 0;
  for (int i = 0; i < n; i++){ // 経由する頂点
    for (int j = 0; j < n; j++){ // 開始頂点
      for (int k = 0; k < n; k++){ // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
        if(j != k && d[j][k] != INF){
          sum += d[j][k];
        }
      }
    }
  }

  return sum;
}

int main() {
  int n,m;
  cin >> n >> m;

  d = vector<vector<ll> >(n, vector<ll>(n, INF));
  for (int i = 0; i < n; i++) d[i][i] = 0;

  rep(i,m){
    int a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    d[a][b] = c;
  }
  ll sum = warshall_floyd(n);;
  
  
  cout << sum << endl;

  return 0;
}