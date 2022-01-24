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
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        string ans = "";
        int cnt = 0;
        int pre = -1;
        for(int i=0;i<str.size();i++){
            int now = str[i] - '0';
            if(now == pre){
                cnt++;
            }else{
                if(cnt != 0) ans += to_string(cnt) + to_string(pre);
                pre = now;
                cnt = 1;
            }
        }
        ans += to_string(cnt) + to_string(pre);
        return ans;
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
