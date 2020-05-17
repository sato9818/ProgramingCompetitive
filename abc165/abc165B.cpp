#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long X;
    cin >> X;
    long long money = 100;
    int year = 0;
    
    while(1){
        if(money >= X){
            break;
        }
        money = money * 1.01;
        year++;
    }
    cout << year << endl;
	return 0;
}