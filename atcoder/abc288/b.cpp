#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n,k;
    cin >> n >> k;
    vector<string> strs;
    rep(i,n){
        string s;
        cin >> s;
        if(i < k){
            strs.push_back(s);
        }
    }
    sort(strs.begin(), strs.end());

    for(auto str :strs){
        cout << str << endl;
    }

    return 0;
}
