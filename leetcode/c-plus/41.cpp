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
    int firstMissingPositive(vector<int>& nums) {
        int split = segregate(nums);
        // cout << split << endl;
        int n = nums.size();
        // if(split == n){
        //     return 1;
        // }
        
        for(int i=split;i<n;i++){
            // cout << abs(nums[i])-1 << endl;
            if(abs(nums[i]) < n +1 - split ){
                nums[abs(nums[i])-1 + split] = -abs(nums[abs(nums[i])-1 + split]);
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout << nums[i] << endl;
        // }
        
        for(int i = split;i<n;i++){
            if(nums[i] > 0){
                return i-split+1;
            }
        }
        return n+1-split;
    }
    int segregate(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] <= 0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
