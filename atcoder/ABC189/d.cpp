#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll power(int n){
    ll sum=1;
    rep(i,n){
        sum *= 2;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    ll sum = 1;
    rep(i, N){
        cin >> s[i];
    }
    rep(i,N){
        if(s[N-1-i] == "OR"){
            sum += power(N-i);
        }
    }
    cout << sum << endl;

    return 0;
}