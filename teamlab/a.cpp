#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {

    vector<int> v(1000001);
    for(int i = 2;i<1000001;i++){
        v[i] = sieve(i);
    }
    for(int i = 2;i<1000001;i++){
        
    }
    for(int i = 2;i<1000001;i++){
        for(int j = 1000000;j>0;j++){
            if(v[j] < v[j])
        }
    }
    return 0;
}