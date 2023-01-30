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
    int H,W,N, h,w;
    cin >> H >> W >> N >> h >> w;

    vector<vector<int>> a(H, vector<int>(W, 0));
    map<int, int> cnt;
    rep(i,H)rep(j,W) {
        cin >> a[i][j];
        cnt[a[i][j]]++;
    }

    map<int, int> sub_cnt, init;

    rep(i,h)rep(j,w){
        sub_cnt[a[i][j]]++;
        init[a[i][j]]++;
    }


    rep(k,H-h+1){
        rep(l,W-w+1){
            int sum = 0;
            for(auto [k,v] : sub_cnt){
                if(cnt[k] == v) sum++;
                // cout << k << ":" << v << endl;
            }
            cout << cnt.size() - sum << " ";
            if(l == W-w) continue;
            rep(i,h){
                sub_cnt[a[i+k][l]]--;
                if(sub_cnt[a[i+k][l]] == 0) sub_cnt.erase(a[i+k][l]);
                sub_cnt[a[i+k][l+w]]++;
            }
        }
        cout << endl;
        
        if(k == H-h) continue;
        rep(j,w){
            init[a[k][j]]--;
            if(init[a[k][j]] == 0) init.erase(a[k][j]);
            init[a[k+h][j]]++;
        }
        sub_cnt = init;
    }


    
     

    return 0;
}
