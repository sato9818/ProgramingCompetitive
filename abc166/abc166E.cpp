#include <iostream>
#include <map> 
#include <cmath> 
using namespace std;
// typedef pair<int, int> P;
typedef long long ll;

ll *L = new long long[200001];
ll *R = new long long[200001];

int main() {
    int N;
    cin >> N;
    map<ll, ll> mp; 
    for(int i=1;i<N + 1;i++){
        ll a;
        cin >> a;
        L[i] = i + a;
        R[i] = i - a;
    }
    ll cnt = 0;
    for(int i=1;i<N+1;i++){
        auto itr = mp.find(L[i]);
        if( itr != mp.end() ) {
            mp[L[i]] = itr->second + 1;
        }else{
            mp[L[i]] = 1;
        }
        // mp[L[i]]++;
        itr = mp.find(R[i]);
        if( itr != mp.end() ) {
            cnt += itr->second;
        }
        // cnt += mp[R[i]];
    }
    
    cout << cnt << endl;

	return 0;
}
