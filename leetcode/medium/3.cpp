#include <bits/stdc++.h>
// #define rep(i,n) for (int i=0;i<(n);i++)
// #define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
// using ll = long long;
// using P = pair<int, ll>;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int ans = 0;
        int start = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(m.find(c) != m.end()){
              start = max(m[c]+1, start);
            }
            ans = max(ans, i - start + 1);
            // cout << i << ": " << start << endl;
            m[c] = i; 
        }
        return ans;
    }
};

int main(){
  Solution s;

  cout << s.lengthOfLongestSubstring("abba") << endl;
  return 0;
}
