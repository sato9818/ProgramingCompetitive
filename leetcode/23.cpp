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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        
        int cnt = 0;
        while(cnt != lists.size()){
            int min = lists[0] -> val;
            int min_index = 0;
            for(int i=1;i<lists.size();i++){
                ListNode* node = lists[i];
                if(node == nullptr){
                    continue;
                }
                if(min > node -> val){
                    min = node -> val;
                    min_index = i;
                }
            }
            dummy -> next = lists[index];
            dummy = dummy -> next;
            lists[index] = lists[index] -> next;
            if(lists[index] == nullptr){
                cnt ++;
            }
        }
        return ans -> next
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
