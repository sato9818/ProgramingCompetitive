#include <iostream>
using namespace std;
int N,M,Q;
int *a = new int[50];
int *b = new int[50];
int *c = new int[50];
int *d = new int[50];
int *A = new int[10];
int ans = 0;
int cnt = 0;

void solve(int j, int min){
    
    if(j == N-1){
        for(int i=min;i<M+1;i++){
            A[j] = i;
            // cout << j << "---------------------------------------" <<  A[j] << endl;
            int sum = 0;
            for(int k=0;k<Q;k++){

                if((A[b[k]-1] - A[a[k]-1]) == c[k]){
                    sum += d[k];
                    
                }
            }
            // cout << "sum is :" << sum << endl;
            if(ans < sum){
                ans = sum;
            }
            cnt++;
        }
        
    }else{
        for(int i=min;i<M+1;i++){
            A[j] = i;
            // cout << j << "---------------------------------------" <<  A[j] << endl;
            solve(j+1,i);
            
        }
        
    }
    
}

int main() {
    cin >> N;
    cin >> M;
    cin >> Q;
    
    for(int i=0;i<Q;i++){
        cin >> a[i];
        cin >> b[i];
        cin >> c[i];
        cin >> d[i];
    }
    // for(int i=0;i<Q;i++)
    //     cout << a[i] << b[i] << c[i] << d[i] << endl;
    solve(0,1);
    // cout << cnt << endl;
    cout << ans << endl;
	return 0;
}