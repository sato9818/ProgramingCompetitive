#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll A,B1;
    long double B;
    cin >> A >> B;
    // B1 = B*100;
    // A *= B1;
    // string str;
    // str = to_string(A);
    // if(A == 0 || B1 == 0 || A < 100){
    //     cout << 0 << endl;
    // }else{
    //     cout << str.substr(0,str.size()-2) << endl;
    // }
    A = A*B;
    cout << A << endl;
    
    return 0;
}