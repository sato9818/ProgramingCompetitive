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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;

    vector<vector<int>> g(n);
    rep(i,n) {
        g[i].push_back(a[i]);
    }

    vector<int> indegrees(n);
    rep(i,n) {
        indegrees[a[i]]++;
    }

    queue<int> q;

	for (int i = 0; i < n; ++i)
	{
		if (indegrees[i] == 0)
		{
			q.push(i);
		}
	}

    vector<int> result;

    while (!q.empty())
	{
		int from = q.front(); q.pop();

		result.push_back(from);

		for (auto to : g[from])
		{
			if (--indegrees[to] == 0)
			{
				q.push(to);
			}
		}
	}

    cout << n- result.size() << endl;

    return 0;
}
