#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  vector<string> str(3);
  cin >> str[0] >> str[1] >> str[2];
  map<char,int> m;
  map<char,int> head; 
  rep(i,3){
    rep(j,str[i].length()){
      if(j == 0){
        head[str[i][j]] = 1;
      }
      m[str[i][j]] = 0; 
    }
    reverse(str[i].begin(), str[i].end());
  }

  if(m.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  vector<int> p(10);
  iota(p.begin(), p.end(), 0);
  
  do{
    int count = 0;
    for(auto kv: m){
      m[kv.first] = p[count];
      count++;
    }
    int flag = 0;
    for(auto kv: head){
      if(m[kv.first] == 0){
        flag = 1;
      }
    }
    if(flag == 1){
      continue;
    }
    vector<ll> num(3,0);
    rep(i,3){
      ll digit = 1;
      rep(j,str[i].length()){
        num[i] += digit * m[str[i][j]];
        digit *= 10;
      }
    }
    // rep(i,3){
    //   cout << num[i] << endl;
    // }
    if(num[0] + num[1] - num[2] == 0){
      rep(i,3){
        cout << num[i] << endl;
      }
      return 0;
    }
  }while(next_permutation(p.begin(),p.end()));

  cout << "UNSOLVABLE" << endl;
  return 0;
}