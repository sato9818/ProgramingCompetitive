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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode();
        ListNode* dummy = node;
        while(l1 != nullptr || l2 != nullptr){
            int val1 = INT_MAX, val2 = INT_MAX;
            if(l1 != nullptr) val1 = l1 -> val;
            if(l2 != nullptr) val2 = l2 -> val;
            if(val1 > val2){
                node -> next = l2;
                l2 = l2 -> next;
            }else{
                node -> next = l1;
                l1 = l1 -> next;
            }
            node = node -> next;
        }
        return dummy -> next;
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
