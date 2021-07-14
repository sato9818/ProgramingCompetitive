#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int a,b,c;
  cin >> a >> b >> c;
  vector<int> loop(10);

  rep(i,10){
    map<int,int> m;
    int cnt = 1;
    int x = i;
    m[i] = 1;
    while(1){
      x = x * i;
      string s = to_string(x);
      x = s[s.length()-1] - '0';
      // cout << x <<endl;
      if(m[x] != 0){
        loop[x] = cnt;
        break;
      }else{
        m[x]++;
      }
      cnt++;
    }
  }
  string s = to_string(a);
  a = s[s.length()-1] - '0';
  b = b % loop[a];
  if(loop[a] == 1){
    cout << a << endl;
  }else if(loop[a] == 2){
    if(b == 0){
      s = to_string(a*a);
      int ans = s[s.length()-1] - '0';
      cout << ans << endl;
    }else{
      cout << a << endl;
    }
  }else if(loop[a] == 4){
    int times;
    if(b == 0 || b == 1){
      times = b;
    }else if(b == 2){
      if(c > 1){
        times = 0;
      }else{
        times = 2;
      }
    }else{
      if(c % 2 == 0){
        times = 4 - b;
      }else{
        times = b;
      }
    }
    
    int mul = a;
    
    if(times == 0){
      times = 4;
    }
    rep(i,times-1){
      a = mul * a;
      // cout << a << endl;
    }
    s = to_string(a);
    a = s[s.length()-1] - '0';
    cout << a << endl;
  }
  
  return 0;
}