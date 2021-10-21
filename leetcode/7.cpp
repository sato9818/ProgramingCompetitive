#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class Solution {
public:
  int reverse(int x) {
    int ans = 0;
    while(x != 0){
      int rem = x % 10;
      x /= 10;
      if(ans > INT_MAX / 10 || ans >= INT_MAX / 10 && rem > INT_MAX % 10) return 0;
      if(ans < INT_MIN / 10 || ans <= INT_MIN / 10 && rem < INT_MIN % 10) return 0;
      ans = ans * 10 + rem;
    }
    return ans;
  }
};

int main(){
  Solution s;
  int x;
  cin >> x;

  cout << s.reverse(x) << endl;
  return 0;
}