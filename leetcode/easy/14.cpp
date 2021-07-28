#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    string first_str = strs[0];
    rep(i, first_str.size()){
      rep1(j,strs.size()){
        if(first_str[i] != strs[j][i]){
          return ans;
        }
      }
      ans += first_str[i];
    }
    return ans;
  }
};

int main(){
  Solution s;

  cout << s.longestCommonPrefix(["dog","racecar","car"]) << endl;
  return 0;
}
