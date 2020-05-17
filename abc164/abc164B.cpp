#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int myhp, myattack, yourhp, yourattack;
    cin >> myhp;
    cin >> myattack;
    cin >> yourhp;
    cin >> yourattack;
    
    if(ceil((double)yourhp/myattack) <= ceil((double)myhp/yourattack)){
        cout << "Yes"<< endl;
    }else{
        cout << "No"<< endl;
    }
	return 0;
}