#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n,m;
  cin >> n >> m;
  vector< queue<int> > c(m);
  vector<int> popable;
  vector< vector<int> > to_c(n+1);

  rep(i,m){
    int k;
    cin >> k;
    rep(j,k){
      int a;
      cin >> a;
      if(j == 0){
        to_c[a].push_back(i);
        if(to_c[a].size() == 2){
          popable.push_back(a);
        }
      }else{
        c[i].push(a);
      }
    }
  }
  int i = 0;

  while(i != popable.size()){
    int color = popable[i];
    rep(j,to_c[color].size()){
      int cy = to_c[color][j];
      if(!c[cy].empty()){
        int ball = c[cy].front(); c[cy].pop();
        to_c[ball].push_back(cy);
        if(to_c[ball].size() == 2){
          popable.push_back(ball);
        }
      }
    }
    i++;
  }

  if(popable.size() == n){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  return 0;
}
