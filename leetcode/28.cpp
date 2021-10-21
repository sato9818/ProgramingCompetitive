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
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }
        for(int i=0;i<haystack.size();i++){
            if(haystack[i] == needle[0]){
                if(needle == haystack.substr(i, needle.size())){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
