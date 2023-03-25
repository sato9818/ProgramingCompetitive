#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<int> z_algorithm(string& str) {
    vector<int> z(str.size());
    if(str.size() == 0){
        return z;
    }
    z[0] = str.size();
    int i=1, j=0;
    int n = str.size();
    while(i < n){
        while(i+j < n && str[i+j] == str[j]) j++;
        z[i] = j;

        if(j == 0){
            i++;
            continue;
        }

        int k = 1;
        while(k < j && z[k] + k < j){
            z[i+k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return z;
}

int main(void){
  string s;
  cin >> s;
  vector<int> z = z_algorithm(s);

  for(auto cnt : z){
    cout << cnt << endl;
  }
  

  return 0;
}