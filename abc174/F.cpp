#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,q;
    cin >> n >> q;
    multiset<int> c;
    map<int, multiset<int>> m;
    rep(i,n){
        int a;
        cin >> a;
        c.insert(a);
        m[i] = c;
    }
    rep(i,q){
        int l,r;
        cin >> l >> r;
        
        int cnt = 0;
        for(int j = l-1; j < r;j++){
            m[c[j]]++;
        }
        cout << m.size() << endl;
    }
    
    
    return 0;
}