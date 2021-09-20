#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  int q;
  cin >> q;

  vector<int> nums;
  multiset<int> s;

  rep(i,q){
    int n;
    cin >> n;
    if(n == 1){
      int x;
      cin >> x;
      nums.push_back(x);
    }else if(n == 2){
      
      if(!s.empty()){
        cout << *s.begin() << endl;
        s.erase(s.begin());
      }else{
        cout << nums[0] << endl;
        nums.erase(nums.begin());
      }
      
    }else{
      rep(j,nums.size()){
        s.insert(nums[j]);
      }
      nums.clear();
    }
  }
  
  return 0;
}
