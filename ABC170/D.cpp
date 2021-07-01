#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> is_prime( 1000000 + 1 ,0);

    rep(i,N){
        cin >> a[i];
        is_prime[a[i]]++;
    }
    sort(a.begin(),a.end());
    
    for( int i = 1; i <= a[N-1]; i++ ){
        if( is_prime[ i ] > 0){
            for( int j = 2 * i; j <= a[N-1]; j += i ){
                is_prime[ j ] = 0;
            }
        }
    }
    int cnt=0;
    rep(i,a[N-1]+1){
        if(is_prime[ i ] == 1){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}