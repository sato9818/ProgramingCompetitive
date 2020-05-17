#include <iostream>
using namespace std;

int main() {
    string S,T;
    cin >> S;
    cin >> T;
    if(S==T.substr(0, T.length()-1)){
        cout << "Yes"<< endl;
    }else{
        cout << "No"<< endl;
    }

	return 0;
}