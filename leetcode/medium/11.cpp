#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;
        int ans = 0;
        while(right > left){
            int r_value = height[right];
            int l_value = height[left];
            ans = max(ans, (right - left) * min(r_value, l_value));
            if(r_value > l_value){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};

int main(){
  Solution s;
  vector<int> test{1,2,1};

  cout << s.maxArea(test) << endl;
  return 0;
}
