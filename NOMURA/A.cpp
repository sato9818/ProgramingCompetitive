#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    int H1,H2,M1,M2,K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    

    cout << (H2 * 60 + M2) - (H1 * 60 + M1) - K << endl;

    return 0;
}