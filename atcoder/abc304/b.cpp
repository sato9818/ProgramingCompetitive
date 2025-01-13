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
    string n;
    cin >> n;
    if(n.size() < 4){
        cout << n << endl;
        return 0;
    }else{
        for(int i =3;i<n.size();i++){
            n[i] = '0';
        }
    }
    cout << n << endl;

    return 0;
}
