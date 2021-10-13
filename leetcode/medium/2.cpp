#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *l3 = new ListNode();
      ListNode *ans = l3;
      int rem = 0;
      while(l1 != nullptr || l2 != nullptr || rem != 0){
        int val1, val2; 
        if(l1 != nullptr){
          val1 = l1 -> val;
        }else{
          val1 = 0;
        }

        if(l2 != nullptr){
          val2 = l2 -> val;
        }else{
          val2 = 0;
        }
        int sum = val1 + val2 + rem;
        l3 -> next = new ListNode(sum % 10);
        // std::cout << sum % 10 << std::endl;
        rem = sum / 10;

        if(l1 != nullptr) l1 = l1 -> next;
        if(l2 != nullptr) l2 = l2 -> next;
        l3 = l3 -> next;
      }
      return ans->next;
    }
};

void print_list(ListNode *n) {
  while (n != nullptr) {
    std::cout << n->val << " ";
    n = n->next;
  }
}

int main(){
  Solution s;
  ListNode *lt1 = new ListNode();
  ListNode *ans1 = lt1;

  ListNode *lt2 = new ListNode();
  ListNode *ans2 = lt2;

  for(int i=0;i<3;i++){
    lt1 -> next = new ListNode(i);
    lt1 = lt1->next;
  }

  for(int i=0;i<3;i++){
    lt2 -> next = new ListNode(i);
    lt2 = lt2->next;
  }
  print_list(ans1);
  print_list(ans2);
  print_list(s.addTwoNumbers(ans1->next, ans2->next));


  return 0;
}
