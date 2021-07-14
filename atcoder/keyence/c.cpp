#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int INF = 998244353;
    int h,w,k;
    cin >> h >> w >> k;
    char g[5001][5001];
    ll cnt[5001][5001];
    int sum = 0;
    rep(i,5001){
        rep(j,5001){
            g[i][j] = 'A';
            cnt[i][j] = 0;
        }
    }
    rep(i,k){
        int hi, wi;
        char ki;
        cin >> hi >> wi >> ki;
        g[hi-1][wi-1] = ki;
    }
    cnt[0][0] = 1;
    for(int i=1;i<h;i++){
        if(g[i-1][0] == 'A'){
            cnt[i][0] = cnt[i-1][0] * 2;
        }else if(g[i-1][0] == 'R'){
            cnt[i][0] = 0;
        }else{
            cnt[i][0] = cnt[i-1][0];
        }
        cnt[i][0] %= INF;
    }
    for(int i=1;i<w;i++){
        if(g[0][i-1] == 'A'){
            cnt[0][i] = cnt[0][i-1] * 2;
        }else if(g[0][i-1] == 'D'){
            cnt[0][i] = 0;
        }else{
            cnt[0][i] = cnt[0][i-1];
        }
        cnt[0][i] %= INF; 
    }
    for(int i=1;i<h;i++){
        for(int j=1;j<w;j++){
            if(g[i-1][j] == 'A' && g[i][j-1] == 'A'){
                cnt[i][j] = (cnt[i-1][j] * 6 + cnt[i][j-1] * 6) % INF;
            }else if(g[i-1][j] == 'A'){
                cnt[i][j] += cnt[i-1][j] * 2 % INF;
                if(g[i][j-1] == 'R' || g[i][j-1] == 'X'){
                    cnt[i][j] += cnt[i][j-1] * 3 % INF;
                }
            }else if(g[i][j-1] == 'A'){
                cnt[i][j] += cnt[i][j-1] * 2 % INF;
                if(g[i-1][j] == 'D' || g[i-1][j] == 'X'){
                    cnt[i][j] += cnt[i-1][j] * 3 % INF;
                }
            }else{
                if(g[i-1][j] == 'D' || g[i-1][j] == 'X'){
                    cnt[i][j] += cnt[i-1][j];
                }
                if(g[i][j-1] == 'R' || g[i][j-1] == 'X'){
                    cnt[i][j] += cnt[i][j-1];
                }
            }
            cnt[i][j] %= INF;
        }
    }
    if(g[h-1][w-1] == 'A'){
        cout << cnt[h-1][w-1] *3 % INF << endl;
    }else{
        cout << cnt[h-1][w-1] << endl;
    }
    
    return 0;
}