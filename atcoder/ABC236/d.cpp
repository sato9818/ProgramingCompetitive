#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;

int ans = 0;

void dfs(vector<vector<int>> a, int n, vector<int> visited, int sum){
    int mn = -1;
    vector<int> remain;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            if(mn == -1){
                mn = i;
                visited[mn] = 1;
            }else{
                remain.push_back(i);
            }
        }
    }
    if(remain.size() == 1){
        // cout << sum << ":" << a[mn][remain[0]] << endl;
        ans = max(ans, sum ^ a[mn][remain[0]]);
        return;
    }
    rep(i,remain.size()){
        visited[remain[i]] = 1;
        dfs(a, n, visited, sum ^ a[mn][remain[i]]);
        visited[remain[i]] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(2*n, vector<int>(n*2));
    vector<int> visited(2*n, 0);
    rep(i,n*2-1){
        for(int j=i+1;j<n*2;j++){
            cin >> a[i][j];
        }
    }
    dfs(a,2*n,visited,0);
  
    cout << ans << endl;
    return 0;
}
