#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,m;
  cin >> n >> m;
  vector< vector<int> > v(n);

  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
  }

  ll sum = 0;
  queue<int> q;

  rep(i,n){
    q.push(i);
    vector<int> visited(n,0);
    visited[i] = 1;
    while(!q.empty()){
      sum++;
      int c = q.front(); q.pop();
      
      for(auto x : v[c]){
        if(!visited[x]){
          q.push(x);
          visited[x] = 1;
        }
      }
    }
  }
  cout << sum << endl;
  return 0;
}