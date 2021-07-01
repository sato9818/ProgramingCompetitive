#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


ll mi = 100100100100100100;
ll N,A,B,C,D;

void ans(ll coin, ll x){
    if(x == N || coin > mi){
        if(coin < mi){
            mi = coin;
        }
        return;
    }
    cout << x << endl;
    if(x > N){
        ans(coin + D, x - 1);
    }else if(N > x){
        ans(coin + C, x*5);
        ans(coin + B, x*3);
        ans(coin + A, x*2);
        ans(coin + D, x + 1);
    }
    // // if(x == 3){
    // //     if(D >= A){
    // //         coin += A + D;
    // //         if(coin < mi){
    // //             mi = coin;
    // //         }
    // //     }else{
    // //         coin += 2 * D;
    // //         if(coin < mi){
    // //             mi = coin;
    // //         }
    // //     }
    // //     return;
    // // }
    // // if(x == 2){
    // //     if(D >= A){
    // //         coin += A + D;
    // //         if(coin < mi){
    // //             mi = coin;
    // //         }
    // //     }else{
    // //         coin += 2 * D;
    // //         if(coin < mi){
    // //             mi = coin;
    // //         }
    // //     }
    // //     return;
    // // }
    // if(x == 1){
    //     coin += D;
    //     if(coin < mi){
    //         mi = coin;
    //     }
    //     return;
    // }
    // cout << x << endl;
    // if(x == 0){
    //     return;
    // }
    
    // if(x % 5 == 0){
    //     ans(coin + C, x / 5);
    // }else if(x % 5 == 1){
    //     ans(coin + C + D, (x - 1) / 5);
    // }else if(x % 5 == 2 && x != 2){
    //     ans(coin + C + D*2, (x - 2) / 5);
    // }else if(x % 5 == 3){
    //     ans(coin + C + D*2, (x + 2) / 5);
    // }else if(x % 5 == 4){
    //     ans(coin + C + D, (x + 1) / 5);
    // }

    // if(x % 3 == 0){
        
    //     ans(coin + B, x / 3);
    // }else if(x % 3 == 1){

    //     ans(coin + B + D, (x - 1) / 3);
    // }else if(x % 3 == 2){
    //     ans(coin + B + D, (x + 1) / 3);
    // }

    // if(x % 2 == 0){

    //     ans(coin + A, x / 2);
    // }else if(x % 2 == 1){
    //     ans(coin + A + D, (x - 1) / 2);
    // }

}

int main() {
    int T;
    cin >> T;

    rep(i,T){
        mi = 100100100100100100;
        cin >> N >> A >> B >> C >> D;
        ll coin = D;
        ll x = 1;
        ans(coin, x);
        cout << mi << endl;
    }
    return 0;
}