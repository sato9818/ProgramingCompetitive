#include <iostream>
using namespace std;

int main() {
    long long A,B,C,K;
    cin >> A >> B >> C >> K;
    long long ans = 0;
    if(K >= A){
        ans = A;
        K = K - A;
    }else{
        ans = K;
        cout << ans << endl;
        return 0;
    }
    if(K == 0){
        cout << ans << endl;
        return 0;
    }
    if(K >= B){
        K -= B;
    }else{
        cout << ans << endl;
        return 0;
    }
    if(K == 0){
        cout << ans << endl;
        return 0;
    }
    if(K >= C){
        ans -= C;
        K -= C;
    }else{
        ans -= K;
        cout << ans << endl;
        return 0;
    }
	cout << ans << endl;
    return 0;
}