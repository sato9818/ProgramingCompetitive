#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int sum=0;
    rep(i,N){
        cin >> a[i];
        sum = sum ^ a[i];
    }
    rep(i,N){
        cout << (sum ^ a[i]);
        if(i != N-1){
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}