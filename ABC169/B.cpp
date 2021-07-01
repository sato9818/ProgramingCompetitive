#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll A, B = 1, N;
    cin >> N;
    int flag = 0;
    rep(i,N){
        cin >> A;
        B *= A;
        if(B > 1000000000000000000){
            B = 0;
        }
        if(A == 0){
            flag = 1;
        }
    }
    if(B == 0 && flag == 0){
        B = -1;
    }
    cout << B << endl;
    return 0;
}