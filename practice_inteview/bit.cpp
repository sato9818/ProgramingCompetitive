#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

class BIT {
public:
    int n;
    vector<int> arr;
    
    BIT(int n): n(n), arr(n+1, 0){};
    
    void add(int idx, int x){
        // cout << x << endl;
        idx++;
        for(int i=idx;i<=n;i+=(i & -i)){
            arr[i] += x;
        }
    }
    
    int sum(int idx){
        idx++;
        int sum = 0;
        // cout << idx << endl;
        for(int i=idx;i>0;i -= (i & -i)){
            sum += arr[i];
        }
        return sum;
    }
    
    int sum_range(int l, int r){
        return sum(r) - sum(l-1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    BIT bit(n);

    rep(i,q){
        int c, x, y;
        cin >> c >> x >> y;
        if(c == 0){
            bit.add(x-1, y);
        }else if(c == 1){
            cout << bit.sum_range(x-1, y-1) << endl;
        }
    }

    

    return 0;
}
