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
    int divide(int dividend, int divisor) {
        int ans = 0;
        int sign = 1;
        if(dividend < 0 && divisor < 0){
            sign = 1;
        }else if(dividend < 0 || divisor < 0){
            sign = -1;
        }
        if(dividend == INT_MIN){
            if(divisor == 1) return INT_MIN;
            if(divisor == -1) return INT_MAX;
        }

        unsigned int abs_dividend = abs(dividend);
        unsigned int abs_divisor = abs(divisor);
        unsigned int ans_divisor = 0;
        for(int i=0;i<32;i++){
            ans_divisor = ans_divisor << 1;
            ans = ans << 1;
            unsigned int num = (abs_dividend >> (31-i)) - ans_divisor;
            if(abs_divisor <= num){
                ans += 1;
                ans_divisor += abs_divisor;
            }
        }
        if(sign == -1){
            return -ans;
        }else{
            return ans;
        }
    }
};

int main(){
    Solution s;

    // cout << s.divide(11, 2) << endl;
    cout << (-11 << 1) << endl;
    return 0;
}
