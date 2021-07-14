#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


// ll mi = 100100100100100100;
ll N,A,B,C,D;

map<ll,ll> memo;
ll ans(ll n){
    ll coin;
    if(memo[n] != 0){
        return memo[n];
    }
    if(n == 1){
        coin = D;
    }else if(n == 2){
        coin = min(2*D, A+D);
    }else if(n == 3){
        coin = min(min(3*D, D+B),A + 2*D);
    }else if(n == 4){
        coin = min(min(min(4*D, 2*D+B),2*A + D),2*D + C);
    }else{
        int a = n % 5;
        coin = min(ans((n-a)/5) + C + a*D,ans((n + (5-a))/5) + C + (5-a)*D);
        a = n % 3;
        coin = min(min(ans((n-a)/3) + B + a*D,ans((n + (3-a))/3) + B + (3-a)*D),coin);
        a = n % 2;
        coin = min(min(ans((n-a)/2) + A + a*D,ans((n + (2-a))/2) + A + (2-a)*D),coin);
        if(n < coin / D){
            coin = n*D;
        }
    }
    return memo[n] = coin;
}

int main() {
    int T;
    cin >> T;

    rep(i,T){
        // mi = 100100100100100100;
        cin >> N >> A >> B >> C >> D;
        ll cost = ans(N);
        cout << cost << endl;
        memo.clear();
    }
    return 0;
}