#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int a,b;
    cin >> a >> b;
    if(a == 1 && b==2 || a==2 && b==3 || a==4 && b==5 || a==5 && b==6 || a==7 && b==8 || a==8 && b==9) {
        cout << "Yes" << endl; 
        return 0;
    }
    cout << "No" << endl;

    return 0;
}
