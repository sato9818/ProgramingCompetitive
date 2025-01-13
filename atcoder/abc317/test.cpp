#include <bits/stdc++.h>
#include<atcoder/all>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<int, ll>;
using mint = modint998244353;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy, int gx, int gy, vector<string>& a, int w, int h) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vector<vector<int>> visited(h, vector<int>(w, INF));
    visited[sx][sy] = 0;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        if (x == gx && y == gy) {
            return visited[x][y];
        }

        // cout << x << " " << y << endl;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (a[nx][ny] == 'x' || a[nx][ny] == '#' || a[nx][ny] == '<' || a[nx][ny] == '>' || a[nx][ny] == '^' || a[nx][ny] == 'v') continue;
            if (visited[nx][ny] == INF) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    int h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    --sx; --sy; --gx; --gy;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    int ans = bfs(sx, sy, gx, gy, a, w, h);
    cout << ans << endl;


    return 0;
}
