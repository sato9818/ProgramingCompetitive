#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(c == 0){
        if(a > b){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }else{
        if(a >= b){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }

    return 0;
}