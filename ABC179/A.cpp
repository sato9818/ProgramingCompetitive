#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string S;
    cin >> S;

   	if(S[S.length()-1]=='s'){
       cout << S << "es" << endl;
    }else{
      cout << S << "s" << endl;
    }
    return 0;
}