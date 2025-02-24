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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = removeUtil(head, n);
        if(cnt == n){
            head = head -> next;
        }
        return head;
    }

    int removeUtil(ListNode* node, int n){
        if(node -> next == nullptr){
            return 1;
        }
        int x = removeUtil(node -> next, n);
        
        if(x == n){
            node -> next = node -> next -> next;
        }

        return x+1;
    }
};

int main(){
  Solution s;

  cout <<  << endl;
  return 0;
}
