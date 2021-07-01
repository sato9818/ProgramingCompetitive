#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

map<int,int> cnt;
vector<int> c(500005);
vector< vector<int> > t(500005);
int flag[500005];

void dfs(int v, int anc){
  // cout << v << endl;
  if(cnt[c[v]] == 0){
    flag[v] = 1;
  }
  cnt[c[v]]++;
  for(auto n : t[v]){
    if(n != anc){
      dfs(n, v);
    }
  }
  cnt[c[v]]--;
}

int main() {
  int n;
  cin >> n;
  
  rep(i,n){
    cin >> c[i];
  }

  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    t[a].push_back(b);
    t[b].push_back(a);
  }
  dfs(0, 0);

  rep(i,n){
    if(flag[i] == 1){
      cout << i+1 << endl;
    }
  }
  
  return 0;
}