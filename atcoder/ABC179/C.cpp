#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;;
    cin >> N;
    int n2 = sqrt(N);
    int sum = 0;
    rep(i,n2){
        for(int j = i;j<N;j++){
            if((i+1)*(j+1) >= N){
                break;
            }
            if((i+1) != (j+1)){
                sum ++;
            }
            sum ++;
        }
    }
    cout << sum << endl;
    return 0;
}