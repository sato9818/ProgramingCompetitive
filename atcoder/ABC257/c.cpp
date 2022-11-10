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
    string s;
    cin >> n >> s;
    vector<int> adults, children;
    rep(i,n){
        int w;
        cin >> w;
        if(s[i] == '0'){
            children.push_back(w);
        }else{
            adults.push_back(w);
        }
    }

    int ans = max(adults.size(), children.size());

    sort(adults.rbegin(), adults.rend());
    sort(children.rbegin(), children.rend());

    int j = 0;
    rep(i,adults.size()){
        while(j<children.size() && adults[i] <= children[j]){
            j++;
        }
        ans = max(i+1+(int)(children.size()-j), ans);
    }

    cout << ans << endl;

    return 0;
}
