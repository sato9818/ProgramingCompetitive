#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a;
    cin >> a;
    int ans = 100 - (a % 100);
    
    cout <<  ans << endl;

    return 0;
}