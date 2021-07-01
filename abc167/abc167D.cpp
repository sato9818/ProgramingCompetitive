#include <bits/stdc++.h>
#include <iostream>
#include<fstream>
#include <map> 
using namespace std;

typedef long long ll;




int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(200001);
    for(int i=1;i<N+1;i++){
        cin >> A[i];
    }
    
    map<int, int> mp;
    
    mp[1] = 0;
    int town = 1;
    int loop;
    int i = 1;
    while(1){
        if(A[town] == 1 || mp[A[town]] != 0 || i == K) {
            loop = i - mp[A[town]];
            K = K - mp[A[town]];
            town = A[town];
            break;
        }else{
            mp[A[town]] = i;
            town = A[town];
        }
        i++;
    }
    K = K % loop;
    for(int i=0;i<K;i++){
        town = A[town];
    }
    cout << town << endl;
	return 0;
}