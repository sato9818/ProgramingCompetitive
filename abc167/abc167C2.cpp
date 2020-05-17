#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll arr[20][20];
ll C[20];
const int INF = 1001001001;

int main(void){
    int N,M,X;
    cin >> N >> M >> X;

    rep(i, N){
        cin >> C[i];
        rep(j, M){
            cin >> arr[i][j];
        }
    }
    
    
    int ans = INF;
    rep(s, 1<<N){
        ll A[20] = {0};
        int sum = 0;
        rep(i, N){
            if(s>>i&1){
                sum += C[i];
                rep(j,M){
                    A[j] += arr[i][j];
                }
            }
        }
        int flag = 1;
        rep(j,M){
            if(A[j] < X){
                flag = 0;
            }
        }
        if(flag == 1){
            ans = min(ans, sum);
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}