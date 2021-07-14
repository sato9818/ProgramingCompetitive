#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);

   	rep(i, N){
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    rep(i, N){
        for(int j=i+1;j<N;j++){
            double v = (double)(b[i] - b[j]) / (a[i] - a[j]);
            if(v <= 1 && v >= -1){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}