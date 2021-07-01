#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N,Q;
    cin >> N;
    vector<int> A(N);
    map<int,int> cnt;
    ll sum = 0;
    rep(i,N){
        cin >> A[i];
        cnt[A[i]]++;
        sum += A[i];
    }
    cin >> Q;

    rep(i,Q){
        int B,C;
        cin >> B >> C;
        int cntA = cnt[B];
        int sub = C - B;
        sum += cntA * sub;
        cnt[C] += cnt[B];
        cnt[B] = 0;
        cout << sum << endl;
    }
    
    return 0;
}