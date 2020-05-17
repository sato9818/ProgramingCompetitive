#include <iostream>
using namespace std;

int main() {
    int K,A,B;
    cin >> K;
    cin >> A;
    cin >> B;
    int ans = 0;
    for(int i=A;i<B+1;i++){
        if(i % K == 0){
            ans =1;
            break;
        }
    }
    if(ans == 0){
        cout << "NG"<< endl;
    }else{
        cout << "OK"<< endl;
    }
	return 0;
}