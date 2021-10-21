#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int sign = 1;
        int ans = 0;
        while(s[index] == ' '){
            index++;
        }
        if(s[index] == '+'){
            sign = 1;
            index++;
        }else if(s[index] == '-'){
            sign = -1;
            index++;
        }
        while(true){
            int num = s[index] - '0';
            if(num < 0 || num > 9){
                break;
            }
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
            ans = 10*ans - num;
            index++;
        }
        return ans*sign;
    }
};

int main(){
  Solution s;

  cout << s.myAtoi("-91283472332") << endl;
  return 0;
}
