#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  rep(i,s.size()){
    if(s[i] == '1'){
      if(i % 2 == 0){
        cout << "Takahashi" << endl;
      }else{
        cout << "Aoki" << endl;
      }
      break;
    }
  }
  return 0;
}
