#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    rep(i,n){
        rep(j,n){
            cin >> arr[i][j];
        }
    }
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(arr[i][j] == 'W' && arr[j][i] == 'L'){
                continue;
            }
            if(arr[i][j] == 'L' && arr[j][i] == 'W'){
                continue;
            }
            if(arr[i][j] == 'D' && arr[j][i] == 'D'){
                continue;
            }
            cout << "incorrect" << endl;
            return 0;
        }
    }
    cout << "correct" << endl;
    return 0;
}
