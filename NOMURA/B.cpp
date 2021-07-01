#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;




int main(void){
    string T;
    cin >> T;
    rep(i,T.size()){
        if(T[i] == '?'){
            T[i] = 'D';
        }
    }
    cout << T << endl;

    return 0;
}