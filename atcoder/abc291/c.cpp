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
    string s;
    cin >> s;

    map<P,int> mp;

    int x = 0, y = 0;
    mp[P(0,0)] = 1;
    
    rep(i,n){
        char ch = s[i];
        if(ch == 'R'){
            x++;
        }else if(ch == 'L'){
            x--;
        }else if(ch == 'U'){
            y++;
        }else{
            y--;
        }
        P point = P(x,y); 
        if(mp[point] == 1){
            cout << "Yes" << endl;
            return 0;
        }else{
            mp[point] = 1;
        }
    }
    cout << "No" << endl;

    return 0;
}
