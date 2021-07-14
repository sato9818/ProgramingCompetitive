#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    rep(i,k){
        cin >> c[i] >> d[i];
    }
    int mx = 0;
    rep(i, 1<<k){
        vector<int> cnt(n+1, 0);
        int sum = 0;
        rep(j, k){
            if(i>>j&1){
                cnt[d[j]]++;
            }else{
                cnt[c[j]]++;
            }
        }
        rep(x, m){
            if(cnt[a[x]] > 0 && cnt[b[x]] > 0){
                sum++;
            }
        }
        mx = max(mx,sum); 
    }
    cout << mx << endl;
    return 0;
}