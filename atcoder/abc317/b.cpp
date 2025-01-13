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
    int n;
    cin >> n;
    set<int> st;
    rep(i,n) {
        int a;
        cin >> a;
        st.insert(a);
    }

    int num = -1;

    for(auto x : st) {
        if(num == -1) {
            num = x;
        }else{
            if(num + 1 != x){
                cout << num + 1 << endl;
                return 0;
            }
            num = x;
        }
    }

    return 0;
}
