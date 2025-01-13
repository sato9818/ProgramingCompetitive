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
    vector<vector<int>> g(n);
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> indegrees(n);
    rep(i,n) {
        indegrees[i] = g[i].size();
    }

    vector<int> tree_size;

    queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (indegrees[i] == 1)
		{
			q.push(g[i][0]);
            break;
		}
	}

    while (!q.empty())
	{
		int from = q.front(); q.pop();
        // cout << "from: " << from << endl;
		// result.push_back(from);
        int ans = 0;
		for (auto to : g[from])
		{
            // cout << "to: " << to << endl;
            ans++;
			if (indegrees[to] != 1)
			{
                int v;
				for(auto to2 : g[to]){
                    if(to2 != from){
                        for(auto to3 : g[to2]){
                            if(to3 != to){
                                q.push(to3);
                            }
                            indegrees[to2] = 1;
                        }
                    }
                }
			}
		}
        tree_size.push_back(ans);
	}

    sort(tree_size.begin(), tree_size.end());
    rep(i,tree_size.size()){
        cout << tree_size[i] << endl;
    }

    return 0;
}
