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
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return -1;
        }

        int head = nums[0];
        if(head == target){
            return 0;
        }

        int right = len;
        int left = 1;
        while(left < right){
            int mid = (right + left) / 2;
            // cout << right << left <<mid << endl;
            int mid_value = nums[mid];
            if(mid_value == target){
                return mid;
            }
            if(head > target){
                if(mid_value < head && mid_value > target){
                    right = mid;
                }else{
                    left = mid+1;
                }
            }else{
                if(mid_value > head && mid_value < target){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
        }
        return -1;

    }
};

int main(){
    Solution s;
    vector<int> test{4,5,6,7,0,1,2};

    cout << s.search(test, 3) << endl;
    return 0;
}
