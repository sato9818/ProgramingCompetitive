#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<double, double>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);

    rep(i,n){
        cin >> x[i] >> y[i];
    }

    if(k == 1){
        cout << "Infinity" << endl;
        return 0;
    }
    vector<vector<int>> checked(n, vector<int>(n, INF));
    int ans = 0;

    rep(i,n){
        for(int j=i+1;j<n;j++){
            vector<int> on_line{i,j};
            if(checked[i][j] != INF){
                continue;
            }
            int cnt = 2;
            for(int l=j+1;l<n;l++){
                if((x[j] - x[i]) * (y[l] - y[i]) == (x[l] - x[i]) * (y[j] - y[i])){
                    cnt++;
                    on_line.push_back(l);
                }
                
                
            }
            if(cnt >= k){
                ans++;
            }
            rep(a,on_line.size()){
                for(int b=a+1;b<on_line.size();b++){
                    checked[on_line[a]][on_line[b]] = cnt;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
