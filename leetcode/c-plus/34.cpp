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
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            vector<int> ans{-1, -1};
            return ans;
        }
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        int idx_lower = distance(nums.begin(), lower);

        auto upper = upper_bound(nums.begin(), nums.end(), target);
        int idx_upper = distance(nums.begin(), upper);

        if(nums[idx_lower] == target){
            vector<int> ans{idx_lower, idx_upper-1};
            return ans;
        }else{
            vector<int> ans{-1, -1};
            return ans;
        }
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
