#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N), cnt(N,0);
    int sum = 0;
    rep(i,N){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int res;
    if(K > cnt[0]){
        res = cnt[0];
    }else{
        res = K;
    }
    for(int i=1;i<N;i++){
        if(cnt[i] < res){
            sum += i * (res - cnt[i]);
            res = cnt[i];
        }
        if(i == N-1){
            sum += i * res;
        }
    }
    cout << sum << endl;
    return 0;
}