#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

int main() {
  int a, b;
  ll k;
  cin >> a >> b >> k;
  vector<vector<long long int> > v(60+1,vector<long long int>(60+1,0));
  comb(v);

  string ans = "";

  int sum = a+b;
  rep(i,sum){
    if(v[a+b-1][a-1] >= k){
      if(a > 0){
        ans += 'a';
        a--;
      }else{
        ans += 'b';
        b--;
      }
      
    }else{
      k -= v[a+b-1][a-1];
      ans += 'b';
      b--;
    }
  }
  cout << ans << endl;
  
  return 0;
}