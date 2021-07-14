#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int K;
    string S;
    cin >> K;
    cin >> S;
    
    if(S.size() <= K){
        cout << S << endl;
    }else{
        cout << S.substr(0,K) + "..." << endl;
    }

	return 0;
}