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

    vector<int> p(n);

    rep(i,n){
        cin >> p[i];
    }

    int prev = p[n-1];
    int pointer = n-2;
    vector<int> elems;
    elems.push_back(prev);
    int target = 0;
    while(true){
        if(p[pointer] > prev){
            target = p[pointer];
            elems.push_back(p[pointer]);
            break;
        }
        elems.push_back(p[pointer]);
        prev = p[pointer];
        pointer--;
    }

    sort(elems.begin(), elems.end());
    int pos = lower_bound(elems.begin(), elems.end(), target) - elems.begin();
    target = p[pointer] = elems[pos-1];

    reverse(elems.begin(), elems.end());

    rep(i,elems.size()){
        if(elems[i] != target) {
            p[pointer+1] = elems[i];
            pointer++;
        }
        
    }

    rep(i,n){
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}
