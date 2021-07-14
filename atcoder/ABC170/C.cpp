#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int X,N;
    cin >> X >> N;
    map<int,int> map;
    rep(i,N){
        int p;
        cin >> p;
        map[p] = 1;
    }
    if(N == 0){
        cout << X << endl;
        return 0;
    }
    for(int i=0;;i++){
        if(map[X-i] != 1){
            cout << X-i << endl;
            return 0;
        }
        if(map[X+i] != 1){
            cout << X+i << endl;
            return 0;
        }
    }
    
    return 0;
}