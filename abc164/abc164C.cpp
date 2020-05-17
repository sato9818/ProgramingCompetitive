#include <iostream>
#include <list>
using namespace std;

int main() {
    int n;
    cin >> n;
    list<string> list1;
    for(int i=0;i<n;i++){
        string name;
        cin >> name;
        list1.push_front(name);
    }
    list1.sort();
    list1.unique();

    // string *various = new string[n];
    // int count = 0;
    // for(int i=0;i<n;i++){
    //     string name;
    //     int flag = 0;
    //     cin >> name;
    //     for(int j=0;j<i;j++){
    //         if(various[j] == name){
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(flag == 0){
    //         various[i] = name;
    //         count++;
    //     }
    // }
    cout << list1.size()<< endl;
	return 0;
}