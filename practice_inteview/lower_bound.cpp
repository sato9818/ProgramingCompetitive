#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int lower_bound_manual(vector<int>& arr, int num){
    int l = 0, r = arr.size();
    while(l < r){
        int m = (r+l) / 2;
        if(arr[m] >= num){
            r = m;
        }else{
            l = m+1;
        }
    }
    return r;
}

int main() {
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    cout << lower_bound_manual(a, 20) << endl;
    return 0;
}
