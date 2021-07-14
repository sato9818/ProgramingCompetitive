#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,q;
  cin >> n >> q;

  vector< vector<int> > r(n);

  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    r[a].push_back(b);
    r[b].push_back(a);
  }
  vector<ll> dist(n,1001001001);
  queue<P> qu;
  qu.push(P(0,0));
  vector<int> visited(n,0);
  visited[0] = 1;

  while(!qu.empty()){
    P p = qu.front(); qu.pop();
    dist[p.first] = p.second;
    for(auto x : r[p.first]){
      if(!visited[x]){
        qu.push(P(x,p.second + 1));
        visited[x] = 1;
      }
    }
  }

  rep(i,q){
    int c,d;
    cin >> c >> d;
    c--;
    d--;
    if(abs(dist[c]-dist[d]) % 2 == 0){
      cout << "Town" << endl;
    }else{
      cout << "Road" << endl;
    }
    
  }
  
  return 0;
}