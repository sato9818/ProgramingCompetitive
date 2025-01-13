#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int toTwo(vector<int>& cnt){
    int num = 0;
    rep(i,10) {
        if(cnt[i] % 2 != 0){
            num ++;
        }
        num = num << 1;
    }
    return num;
}

int main() {
    string s;
    cin >> s;
    vector<ll> guuki_cnt(1<<10 + 1, 0);
    vector<int> cnt(10);

    ll sum = 0;
    guuki_cnt[0] = 1;
    auto calc = [&]() {
        guuki_cnt[toTwo(cnt)]++;
    };
    rep(i,s.size()) {
        cnt[s[i]-'0']++;
        sum += guuki_cnt[toTwo(cnt)];
        // cout << i << " " << sum << endl;
        calc();
    }
    cout << sum << endl;

    return 0;
}
