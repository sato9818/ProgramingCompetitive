#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;



int main() {
	
    int *H = new int[100001];
    int *B = new int[100001];
    int N,M;
    cin >> N >> M;

    for(int i=1;i<N+1;i++){
        cin >> H[i];
    }

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        if(H[a] > H[b]){
            B[b]++;
        }else if(H[a] < H[b]){
            B[a]++;
        }else{
            B[b]++;
            B[a]++;
        }
    }
    int cnt = 0; 
    for(int i=1;i<N+1;i++){
        if(B[i] == 0){
            cnt++;
        }
    }
    cout << cnt << endl;

	return 0;
}