#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        for(int i=0;i<(2<<n);i++){
            string sub = "";
            for(int j=0;j<n;j++){
                if(i>>j == 1){
                    sub += "(";
                }else{
                    sub += ")";
                }
            }
            if(isValid(sub)){
                ans.push_back(sub);
            }
        }
        return ans;
    }
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
