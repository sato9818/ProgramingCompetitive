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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int cnt_x = 0, cnt_y = 0;
    for(auto ch : s){
        if(ch == 'X'){
            cnt_x++;
        }else{
            cnt_y++;
        }
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<int> xs,ys;
    int sum = 0;
    if(cnt_x >= k){
        int cnt = 0;
        for(auto ch : s){
            if(ch == 'X'){
                cnt++;
            }else{
                xs.push_back(cnt);
                cnt = 0;
            }
        }
        xs.push_back(cnt);
        rep1(i,n){
            if(s[i-1] == 'Y' && s[i] == 'Y'){
                sum++;
            }
        }
        
        // int first = xs[0];
        // int last = xs[xs.size()-1];
        if(xs.size() == 1){
            cout << max(k-1, 0) << endl;
            return 0;
        }
        xs.erase(xs.begin());
        xs.pop_back();
        sort(xs.begin(), xs.end());
        
        int j = 0;
        while(j < xs.size() && xs[j] <= k){
            if(xs[j] == 0){
                j++;
                continue;
            }
            k -= xs[j];
            sum += xs[j] + 1;
            j++;
        }
        if(k > 0){
            sum += k;
        }
    }else{
        int cnt = 0;
        k -= cnt_x;
        for(auto ch : s){
            if(ch == 'Y'){
                cnt++;
            }else{
                ys.push_back(cnt);
                cnt = 0;
            }
        }
        ys.push_back(cnt);
        // for(auto y : ys){
        //     cout << y << endl;
        // }
        
        int edge = ys[0] + ys[ys.size()-1];
        // cout << "edge: " << edge << endl;
        if(edge >= k){
            cout << max(n-1-k,0) << endl;
            return 0;
        }else{
            sum = n-1-edge;
            k -= edge;
        }
        ys.erase(ys.begin());
        ys.pop_back();
        
        sort(ys.rbegin(), ys.rend());
        int j = 0;
        // cout << "sum: " << sum << endl;
        // cout << "k: " << k << endl;
        while(j < ys.size() && ys[j] <= k){
            // cout << ys[j] << endl;
            if(ys[j] == 0){
                j++;
                continue;
            }
            k -= ys[j];
            sum -= (ys[j] + 1);
            j++;
        }
        //  cout << "k: " << k << endl;
        if(k > 0){
            sum -= (k+1);
        }
    }

    cout << sum << endl;

    return 0;
}
