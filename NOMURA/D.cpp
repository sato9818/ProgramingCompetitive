#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;




int main(void){
    int N;
    cin >> N;
    vector< vector<int> > data(N+1, vector<int>(N+1 , 0));
    vector<int> P(N+1,0);
    ll ans = 0;
    int countP = 0;
    int minusc = 0;
    rep(i,N){
        cin >> P[i+1];
        if(P[i+1] != -1){
            data[i+1][P[i+1]]++;
            data[P[i+1]][i+1]++;
            if(data[i+1][P[i+1]] == 1){
                countP++;
            }
        }else{
            minusc ++;
        }
    }
    
    rep(i,N){
        if(P[i+1] == -1){
            int cnt = 0;
            rep(j,N){
                if(data[i+1][j+1] > 0){
                    cnt++;
                }
            }
            ans += pow(N-1,minusc) - cnt ;
            
        }
    }
    ans += countP * pow(N-1,minusc);
    if(minusc > 1){
        ans -= (minusc * (minusc - 1)) / 2;
    }
    cout << ans << endl;

    return 0;
}