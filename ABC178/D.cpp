#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MX = 10000;
const int MOD = 1000000007;

long long fac[MX], finv[MX], inv[MX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int s;
    cin >> s;
    COMinit();
    
    int div = s / 3;
    ll sum = 0;
    
   	rep(i,div){
        if(i == 0){
            sum += 1;
        }else{
            int a = s + 1 - 4 - 2*i;
            sum += COM(a, i);
            sum %= MOD;
        }

    }
    cout << sum << endl;
    return 0;
}