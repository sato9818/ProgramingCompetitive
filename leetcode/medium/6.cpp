#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> strs(numRows, "");
        int eff = 1;
        int index = 0;
        for(int i=0;i<s.size();i++){
            strs[index] += s[i];
            index += eff;
            if(index % (numRows-1) == 0){
                eff *= -1;
            } 
        }
        string ans = "";
        for(int i=0;i<numRows;i++){
            ans += strs[i];
        }
        return ans;
    }
};

int main(){
    Solution s;

    cout << s.convert("A", 1) << endl;
    return 0;
}
