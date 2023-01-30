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

    vector< vector<int> > ladder(n * 2);
    map<int,int> height_to_index, index_to_height;
    height_to_index[1] = 0;
    index_to_height[0] = 1;
    int index = 1;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        if(height_to_index.count(a) == 0) {
            height_to_index[a] = index;
            index_to_height[index] = a;
            index++;
        }
        if(height_to_index.count(b) == 0) {
            height_to_index[b] = index;
            index_to_height[index] = b;
            index++;
        }
        ladder[height_to_index[a]].push_back(height_to_index[b]);
        ladder[height_to_index[b]].push_back(height_to_index[a]);
    }
    // cout << ladder[0].size() << endl;
    queue<int> q;
    q.push(height_to_index[1]);
    int ans = 0;
    map<int,int> visited;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans = max(ans, index_to_height[now]);
        if(visited[now] == 1) continue;
        // cout << now << " " << index_to_height[now] << endl;
        visited[now] = 1;
        for(auto next:ladder[now]){
            
            if(visited[next] == 1) continue;
            q.push(next);
        }
    }

    cout << ans << endl;

    return 0;
}
