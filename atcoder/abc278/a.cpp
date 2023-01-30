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
    int n, k;
    cin >> n >> k;
    deque<int> q;
    rep(i,n){
        int a;
        cin >> a;
        q.push_back(a);
    }

    rep(i,k) {
        q.pop_front();
        q.push_back(0);
    }

    while(q.size()){
        cout << q.front() << endl;
        q.pop_front();
    }

    return 0;
}
