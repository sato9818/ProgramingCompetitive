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

    unordered_map<int,int> lcm, second_lcm;
    vector<vector<P>> nums(n);
    
    rep(i,n){
        int m;
        cin >> m;
        rep(j,m){
            int p,e;
            cin >> p >> e;
            if(lcm[p] > 0){
                if(lcm[p] < e){
                    second_lcm[p] = lcm[p];
                    lcm[p] = e;
                }else{
                    second_lcm[p] = max(second_lcm[p], e);
                }
            }else{
                lcm[p] = e;
            }
            nums[i].push_back(P(p,e));
        }
    }

    int ans = 0;
    int flag = 0;

    rep(i,n){
        rep(j,nums[i].size()){
            P num = nums[i][j];
            int p = num.first, e = num.second;
            if(lcm[p] == e && second_lcm[p] != e){
                ans++;
                break;
            }
            if(j == nums[i].size()-1){
                if(!flag){
                    ans++;
                    flag = 1;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
