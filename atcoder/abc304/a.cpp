#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<string, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int main() {
    int n;
    cin >> n;
    vector<P> h(n);
    int age = INF;
    int ind = -1;
    rep(i,n) {
        string s;
        int a;
        cin >> s >> a;
        h[i] = P(s, a);
        if(age > a) {
            age = a;
            ind = i;
        }
    }

    for(int i = ind; i<n;i++){
        cout << h[i].first<< endl;
    }

    for(int i = 0; i<ind;i++){
        cout << h[i].first<< endl;
    }

    return 0;
}
