#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long C[20];

// vector< vector<int> > arr(20, vector<int>(20));
ll arr[20][20];
long long N,M,X;
ll mi = 100000000;

void dfs(ll i, ll sum, bool b, ll* A);

int main() {
    
    cin >> N >> M >> X;
    for(int i=0;i<N;i++){
        cin >> C[i];
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            // cout << arr[i][j] << endl;
        }
    }
    long long A[20] = {0};
    dfs(0,0,false,A);
    dfs(0,C[0],true,A);
    if(mi == 100000000) cout << -1 << endl;
    else cout << mi << endl;
	return 0;
}

void dfs(ll i, ll sum, bool b, ll* A){
    long long B[20];
    if(b == true){
        for(int j=0;j<M;j++){
            B[j] = A[j] + arr[i][j]; 
        }
    }else{
        for(int j=0;j<M;j++){
            B[j] = A[j]; 
        }
    }
    if(i == N - 1){
        int flag = 1;
        for(int j=0;j<M;j++){
            // cout << B[j] << endl;
            if(B[j] < X){
                flag = 0;
            } 
        }
        // cout << sum << endl;
        if(flag == 1){
            // cout << i << endl;
            // cout << b << endl;
            if(mi > sum){
                // cout << i << endl;
                mi = sum;
            }
        }
        return;
    }

    dfs(i + 1, sum, false, B);
    dfs(i + 1, sum + C[i+1], true, B);
}