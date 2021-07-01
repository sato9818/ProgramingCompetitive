#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N){
        cin >> x[i] >> y[i];
    }
    int M;
    cin >> M;
    vector<string> op(M);
    rep(i,M){
        cin >> op[i];
    }
    int Q;
    cin >> Q;
    vector<string> a(Q);
    rep(i,Q){
        cin >> op[i];
    }
    
    cout << sum << endl;

    return 0;
}