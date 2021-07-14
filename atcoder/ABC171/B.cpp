#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N,K;
    cin >> N >> K;
    vector<int> p(N);
    rep(i,N){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int sum = 0;
    rep(i,K){
        sum += p[i];
    }
    cout << sum << endl;
    return 0;
}