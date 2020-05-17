#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    N = N % 10;
    
    if(N == 2 || N==4 || N==5 || N==7 || N==9){
        cout << "hon"<< endl;
    }else if(N == 0 || N==1 || N==6 || N==8 ){
        cout << "pon"<< endl;
    }else{
        cout << "bon"<< endl;
    }

	return 0;
}