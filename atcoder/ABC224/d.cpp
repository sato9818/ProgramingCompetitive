#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, string>;
using PP = pair<P, int>;

int main() {
  int m;
  cin >> m;
  vector<vector<int> > e(9);
  vector<int> p(9,8);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  rep(i,8){
    int x;
    cin >> x;
    p[x-1] = i;
  }
  string start;
  int epos;
  rep(i,9){
    start += '0' + p[i];
    if(p[i] == 8) epos = i;
  }
  // cout << start << endl;
  map<string,int> mp;
  priority_queue<PP, vector<PP>, greater<PP>> q;
  q.push(PP(P(0, start), epos));

  auto judge = [&](string str){
    if(str == "012345678"){
      return true;
    }else{
      return false;
    }
  };
  
  while(!q.empty()){
    PP v = q.top(); q.pop();
    P vc = v.first;
    if(mp[vc.second] > 0){
      continue;
    }
    if(judge(vc.second)){
      cout << vc.first << endl;
      return 0;
    }
    int pos = v.second;
    mp[vc.second] = 1;
    for(auto i : e[pos]){
      string tmp = vc.second;
      swap(tmp[pos], tmp[i]);
      q.push(PP(P(vc.first+1, tmp), i));
    }
    
  }

  cout << -1 << endl;


  return 0;
}
