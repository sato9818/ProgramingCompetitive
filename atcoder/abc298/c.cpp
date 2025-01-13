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
    int n, q;
    cin >> n >> q;
    map<int,multiset<int>> boxCard;
    map<int,set<int>> cardBox;
    while(q--){
        int t;
        cin >> t;
        int i,j;
        if(t == 1){
            cin >> i >> j;
            boxCard[j].insert(i);
            cardBox[i].insert(j);
        }else if(t == 2){
            cin >> i;
            for(auto x: boxCard[i]){
                cout << x << " ";
            }
            cout << endl;
        }else {
            cin >> i;
            for(auto x: cardBox[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
