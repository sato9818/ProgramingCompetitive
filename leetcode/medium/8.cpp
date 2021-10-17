#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;


class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        int sign = 1;
        int start = 0;
        for(int i=0;i<s.size();i++){
            if(!start){
                if(s[i] == ' '){
                    continue;
                }else if(s[i] == '-'){
                    sign = -1;
                    start = 1;
                    continue;
                }else if(s[i] == '+'){
                    sign = 1;
                    start = 1;
                    continue;
                }
            }
            
            int num = s[i] - '0';
            if(num < 0 || num > 9){
                break;
            }
            start = 1;
            if(sign == -1){
                if(ans > (INT_MIN/10 * -1)){
                    return INT_MIN;
                }else if(ans == (INT_MIN/10 * -1)){
                    // cout << INT_MIN % 10 << endl;
                    if(num >= (INT_MIN % 10 * -1)){
                        return INT_MIN;
                    }
                }
            }else if(sign == 1){
                if(ans > INT_MAX/10){
                    return INT_MAX;
                }else if(ans == INT_MAX/10){
                    if(num > (INT_MAX % 10)){
                        return INT_MAX;
                    }
                }
            }
            ans = 10 * ans + num;
        }
        return ans*sign;
    }
};

int main(){
  Solution s;

  cout << s.myAtoi("-2147483647") << endl;
  return 0;
}
