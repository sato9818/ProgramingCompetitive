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
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    rep(i,m){
        int a;
        cin >> a;
        a--;
        mp[a]++;
    }

    stack<int> st;

    rep(i,n) {
        if(mp.count(i) > 0) {
            st.push(i);
        }else{
            cout << i+1 << " ";
            while(!st.empty()){
                cout << st.top()+1 << " ";
                st.pop();
            }
        }
    }
    cout << endl;

    return 0;
}
