#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
  map<char,int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
  int romanToInt(string s) {
    int sum = 0;
    rep(i, s.size()){
      if(i != s.size()-1){
        if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
          sum += m[s[i+1]] - m[s[i]];
          i++;
        }else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
          sum += m[s[i+1]] - m[s[i]];
          i++;
        }else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
          sum += m[s[i+1]] - m[s[i]];
          i++;
        }else{
          sum += m[s[i]];
        }
      }else{
        sum += m[s[i]];
      }
    }
    return sum;
  }
};

int main(){
  Solution s;

  cout << s.romanToInt("LVIII") << endl;
  return 0;
}
