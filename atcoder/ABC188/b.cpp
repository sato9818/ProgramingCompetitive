#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    int sum = 0;

    vector<int> a(N), b(N);

    rep(i,N){
        cin >> a[i];
    }
    rep(i,N){
        cin >> b[i];
    }
    rep(i,N){
        sum += a[i] * b[i];
    }
    if (sum ==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}