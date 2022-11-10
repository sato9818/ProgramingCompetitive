#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

void ask(int a, int b, int c, int d){
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
}

int main() {
    int n;
    cin >> n;
    int ansi, ansj;

    int mx = n;
    int mn = 1;
    
    
    while(mn < mx){
        int half = (mx+mn) / 2;
        ask(mn,half,1,n);
        
        int res;
        cin >> res;
        if(res == -1){
            return 0;
        }
        if(res == (half - mn + 1)){
            mn = half + 1;
        }else{
            mx = half;
        }
    }
    ansi = mn;

    mx = n;
    mn = 1;

    while(mn < mx){
        int half = (mx+mn) / 2;
        ask(1,n,mn,half);
        
        int res;
        cin >> res;
        if(res == -1){
            return 0;
        }
        if(res == (half - mn + 1)){
            mn = half + 1;
        }else{
            mx = half;
        }
    }

    ansj = mn;

    cout << "! " << ansi << " " << ansj << endl; 

    return 0;
}
