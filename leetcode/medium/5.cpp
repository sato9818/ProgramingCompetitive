#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int max_len = 0;
        int center = 0;

        for(int i=0;i<len;i++){
            int len1 = max(checkFromCenter(s, i, i), checkFromCenter(s, i, i+1)); 
            if(len1 > max_len){
                max_len = len1;
                center = i;
            }
        }
        // cout << max_len << endl;
        if(max_len % 2 == 0){
            return s.substr(center - max_len/2 + 1, max_len);
        }else{
            return s.substr(center - max_len/2, max_len);
        }
    }

    int checkFromCenter(string s, int left, int right){
        int len = s.size();
        // cout << left << endl;
        while(right < len && left >= 0 && s[right] == s[left]){
            right++;
            left--;
        }
        return right - left -1;
    }
};



int main(){
    Solution s;

    cout << s.longestPalindrome("ac") << endl;
    return 0;
}
