#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        map<int,string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        if(digits.size() != 0)
            dfs(m,digits,0,"");

        return ans;
    }

    void dfs(map<int,string>& m, string digits, int index, string unite){
        if(digits.size() == unite.size()){
            ans.push_back(unite);
            return;
        }
        string str = m[(int)(digits[index] - '0')];
        for(int i=0;i<str.size();i++){
            dfs(m, digits, index+1, unite+str[i]);
        }
    } 
};

int main(){
    Solution s;
    vector<string> test = s.letterCombinations("2");

    for(int i=0;i<test.size();i++){
        cout << test[i] << endl;
    }
  
  return 0;
}
