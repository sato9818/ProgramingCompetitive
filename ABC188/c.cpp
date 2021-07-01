#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int powtwo(int k){
    int sum = 1;
    rep(i,k){
        sum = sum * 2;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    int max1 = 0, max2 = 0;
    int index1, index2;
    N = powtwo(N);
    rep(i, N/2){
        int a;
        cin >> a;
        if(max1 < a){
            max1 = a;
            index1 = i;
        }
    }
    for(int i = N/2;i<N;i++){
        int a;
        cin >> a;
        if(max2 < a){
            max2 = a;
            index2 = i;
        }
    }
    if(max1 > max2){
        cout << index2 + 1 << endl;
    }else{
        cout << index1 + 1 << endl;
    }
    

    return 0;
}