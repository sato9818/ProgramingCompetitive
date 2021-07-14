#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> s(4,0);
  rep(i,N){
    string str;
    cin >> str;
    if(str == "AC"){
      s[0]++;
    }else if(str == "WA"){
      s[1]++;
    }else if(str == "TLE"){
      s[2]++;
    }else if(str == "RE"){
      s[3]++;
    }
  }
  cout << "AC x " << s[0] << endl;
  cout << "WA x " << s[1] << endl;
  cout << "TLE x " << s[2] << endl;
  cout << "RE x " << s[3] << endl;
  	return 0;
}