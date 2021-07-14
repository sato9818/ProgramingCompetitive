#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    int maxA = 0, maxB = 0;

   	vector<int> a(N), b(N);
    vector<ll> c(N);
    
    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        cin >> b[i];
    }
    maxA = a[0];
    c[0] = (ll)a[0] * b[0];
    cout << c[0] << endl;
    for(int i=1;i<N;i++){
        maxA = max(maxA, a[i]);
        c[i] = max(c[i-1], (ll)maxA * b[i]);

        cout << c[i] << endl;
    }

    

    return 0;
}