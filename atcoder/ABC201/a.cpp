#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

int main() {
  vector<int> a(3);
  rep(i,3){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  if(a[2] - a[1] == a[1] - a[0]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}