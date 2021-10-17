#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;    
        int len_nums = nums.size();
        sort(nums.begin(), nums.end());
        set<int> s;

        for(int i=0;i<len_nums;i++){
            map<int, int> m;
            int l = i + 1;
            int r = len_nums - 1;
            if(s.find(nums[i]) != s.end()){
                continue;
            }
            s.insert(nums[i]);

            while(l>r){
                int sum = nums[l] + nums[r];
                if(sum < -nums[i]){
                    l++;
                }else if(sum > -nums[i]){
                    r--;
                }else{
                    vector<int> triple{nums[i], nums[l], nums[r]};
                    ans.push_back(triple);
                    r--;
                    while(nums[r] == nums[r+1]){
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> test{-1,0,1,2,-1,-4};
    vector<vector<int>> ans;
    ans = 
    for(int i=0;i<)
    cout << s.threeSum(test) << endl;
  return 0;
}
