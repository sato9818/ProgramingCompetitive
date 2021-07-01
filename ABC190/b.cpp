#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,s,d;
    cin >> n >> s >> d;
    int flag = 0;
    rep(i,n){
        int x,y;
        cin >> x >> y;
        if(x < s && y > d){
            flag = 1;
        }
    }
    if(flag == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}