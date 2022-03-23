#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

string s;

int dfs(ll t, ll j){
    if(t == 0){
        if(s[j] == 'A'){
            return 0;
        }else if(s[j] == 'B'){
            return 1;
        }else if(s[j] == 'C'){
            return 2;
        }
    }
    if(j % 2 == 0){
        return (1 + dfs(t-1, j/2)) % 3;
    }else{
        return (2 + dfs(t-1, j/2)) % 3;
    }
}

int dfs2(ll j){
    if(j == 0){
        if(s[0] == 'A'){
            return 0;
        }else if(s[0] == 'B'){
            return 1;
        }else if(s[0] == 'C'){
            return 2;
        }
    }
    if(j % 2 == 0){
        return (1 + dfs2(j/2)) % 3;
    }else{
        return (2 + dfs2(j/2)) % 3;
    }
}

char solve(ll t, ll k){
    ll p1 = 1;
    int i = 0;
    int flag = 0;
    if(t < 70){
        return dfs(t, k) + 'A';
    }

    for(i=0;;i++){
        if(p1 > k){
            break;
        }
        p1 *= 2;
    }
    vector<char> cs{'A', 'B', 'C'};
    int cint = dfs2(k);
    char ans = cs[((t-i) % 3 + cint) % 3];
    return ans;
}

int main() {
    cin >> s;
    int q;
    cin >> q;
    rep(i,q){
        ll t,k;
        cin >> t >> k;
        char ans = solve(t,k-1);
        cout << ans << endl;
    }
    
    return 0;
}
