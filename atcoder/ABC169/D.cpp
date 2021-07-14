#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;
	cin >> N;

	vector<pair<ll,int> > x;
	ll num = N; 
    int cnt = 0;
	for (ll i = 2; i*i <= N; i++){
        int cnt = 0;
        while(num % i == 0){
            num /= i;
            cnt++;
        }
        x.emplace_back(i,cnt);
	}
    if(num != 1){
        x.emplace_back(num,1);
    }
    int ans = 0;
    for(auto p: x){
        int c = p.second;
        int k = 1;
        while(k <= c){
            ans++;
            c -= k;
            k++;
        }
    }
    cout << ans << endl;
    return 0;
}