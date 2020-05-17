#include <iostream>
using namespace std;

int o[100];

int main() {
    int N,K;
    cin >> N >> K;
    int d;
    for(int i=0;i<K;i++){
        cin >> d;
        for(int j=0;j<d;j++){
            int a;
            cin >> a;
            o[a-1]++;
        }
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(o[i] == 0){
            cnt++;
        }
    }
    cout << cnt<< endl;

	return 0;
}