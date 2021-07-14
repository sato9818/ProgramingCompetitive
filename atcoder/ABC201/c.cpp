#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  string s;
  cin >> s;
  vector<int> ok, ng, hatena;
  rep(i, s.length()){
    if(s[i] == 'o'){
      ok.push_back(i);
    }else if(s[i] == 'x'){
      ng.push_back(i);
    }else if(s[i] == '?'){
      hatena.push_back(i);
    }
  }
  int cnt = 0;
  rep(i,10000){
    int flag = 0;
    string num = to_string(i);
    int digit = 4 - num.length();

    rep(j,digit){
      num = "0" + num;
    }

    rep(j,ok.size()){
      if(num.find(to_string(ok[j])) == std::string::npos){
        flag = 1;
        break;
      }
    }
    rep(j,ng.size()){
      if(num.find(to_string(ng[j])) != std::string::npos){
        flag = 1;
        break;
      }
    }

    if(flag == 0){
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}