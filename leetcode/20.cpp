#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
          char c = s[i];
          if(c == '{' || c == '(' || c == '['){
            st.push(c);
          }else{
            if(st.size() == 0){
              return false;
            }
            char c2 = st.top(); st.pop();
            if(!((int)(c - c2) == 1 || (int)(c - c2) == 2)){
              return false;
            }
          }
        }
        if(st.size() != 0){
          return false;
        }
        return true;
    }
};

int main(){
  Solution s;

  cout <<  << endl;
  return 0;
}
