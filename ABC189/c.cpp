#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N){
        cin >> a[i];
    }
    int mx = 0;
    
    rep(i,N){
        int hei = a[i];
        for(int j=i;j<N;j++){
            hei = min(hei, a[j]);
            mx = max(mx, hei*(j-i+1));
        }
    }
    
    cout << mx << endl;

    return 0;
}