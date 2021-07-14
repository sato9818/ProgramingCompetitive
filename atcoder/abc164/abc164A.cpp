#include <iostream>
using namespace std;

int main() {
    int sheep;
    cin >> sheep;
    int wolve;
    cin >> wolve;
    if(sheep>wolve){
        cout << "safe"<< endl;
    }else{
        cout << "unsafe"<< endl;
    }
	return 0;
}