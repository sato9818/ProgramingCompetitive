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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> num(n,0);
    multiset<int> msl;
    multiset<int, greater<int>> msg;

    ll sum = 0;
    rep(i,k) {
        msl.insert(0);
    }
    rep(i,n-k) {
        msg.insert(0);
    }

    rep(i,q) {
        int x, y;
        cin >> x >> y;
        x--;
        int least = *msl.begin();
        int most = *msg.begin();
        if(msg.find(num[x]) != msg.end()/*元の値が下位に入っている*/) {
            if(y > least/*yが上位kに入るとき*/){
                msg.erase(msg.find(num[x]));
                msl.erase(msl.find(least));
                msg.insert(least);
                msl.insert(y);
                sum = sum - least + y;
            }else{
                msg.erase(msg.find(num[x]));
                msg.insert(y);
            }
        }else/*上位に入っている*/{
            if(y >= least/*yが上位kに入るとき*/){
                msl.erase(msl.find(num[x]));
                msl.insert(y);
                sum = sum - num[x] + y;
            }else{
                msl.erase(msl.find(num[x]));
                msg.insert(y);
                int cur_most = *msg.begin();
                msl.insert(cur_most);
                msg.erase(msg.find(cur_most));
                sum = sum - num[x] + cur_most;
            }
        }
        // for(auto a : msl) {
        //     cout << a << " ";
        // }
        // cout << endl;
        // for(auto a : msg) {
        //     cout << a << " ";
        // }
        // cout << endl;
        num[x] = y;
        cout << sum << endl;
    }

    return 0;
}
