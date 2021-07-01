#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    string ans = "";

    while(N-1 >= 26){
        ll a = (N-1) % 26;
        N = (N-1) / 26;
        string str(1, 'a' + a);
        ans = str + ans;
    }
    string s(1, 'a' + (N - 1));
    ans = s + ans;
    cout << ans << endl;
    return 0;
}