#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int xi[4] = {1,0,-1,0};
int yi[4] = {0,1,0,-1};

struct Edge {
  int to, t, k;
  Edge(int to, int t, int k): to(to), t(t), k(k) {}
}; 


// int bfs(int sx, int sy, int gx, int gy, vector<string>& a, int w, int h) {
//     queue<Edge> q;
//     q.push(Edge(sx, sy, 0));
//     vector<vector<int>> visited(h, vector<int>(w, 0));
//     while(q.size()) {
//         Edge e = q.front(); q.pop();
//         int x = e.to;
//         int y = e.t;
//         int k = e.k;
//         if(x == gx && y == gy) {
//             return k;
//         }
//         if(visited[x][y] == 1) {
//             continue;
//         }
//         cout << x << " " << y << endl;
//         visited[x][y] = 1;
//         rep(ind,4) {
//             int nx = x + xi[ind];
//             int ny = y + yi[ind];
//             if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
//                 continue;
//             }
//             if(a[nx][ny] == '.' || a[nx][ny] == 'G') {
//                 q.push(Edge(nx, ny, k+1));
//             }
//         }
//     }
//     return -1;
// }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int sx, int sy, int gx, int gy, vector<string>& a, int w, int h, vector<vector<bool>>& views) {
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
            if (a[nx][ny] == '#' || a[nx][ny] == '<' || a[nx][ny] == '>' || a[nx][ny] == '^' || a[nx][ny] == 'v') continue;
            if (views[nx][ny]) continue;
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
    vector<string> a(h);

    rep(i,h) {
        cin >> a[i];
    }

    vector<vector<bool>> views(h, vector<bool>(w, false));

    rep(i,h) {
        rep(j,w) {
            if(a[i][j] == '>') {
                j++;
                while(j < w && a[i][j] == '.') {
                    views[i][j] = true;
                    ++j;
                }
                j--;
            }
        }
    }

    rep(i,h) {
        for(int j = w-1; j >= 0; --j) {
            if(a[i][j] == '<') {
                j--;
                while(j >= 0 && a[i][j] == '.') {
                    views[i][j] = true;
                    --j;
                }
                j++;
            }
        }
    }

    rep(j,w) {
        rep(i,h) {
            if(a[i][j] == 'v') {
                i++;
                while(i < h && a[i][j] == '.') {
                    views[i][j] = true;
                    ++i;
                }
                i--;
            }
        }
    }

    rep(j,w) {
        for(int i = h-1; i >= 0; --i) {
            if(a[i][j] == '^') {
                i--;
                while(i >= 0 && a[i][j] == '.') {
                    views[i][j] = true;
                    --i;
                }
                i++;
            }
        }
    }

    // for(int i=0;i<h;i++)for(int j=0;j<w;j++)
	// {
	// 	char c=a[i][j];
	// 	if(c=='>')
	// 	{
	// 		// for(int k=j+1;k<w;k++)
	// 		// {
	// 		// 	if(a[i][k]!='.')break;
	// 		// 	views[i][k]=true;
	// 		// }
	// 	}
	// 	else if(c=='<')
	// 	{
	// 		for(int k=j-1;k>=0;k--)
	// 		{
	// 			if(a[i][k]!='.')break;
	// 			views[i][k]=true;
	// 		}
	// 	}
	// 	else if(c=='^')
	// 	{
	// 		for(int k=i-1;k>=0;k--)
	// 		{
	// 			if(a[k][j]!='.')break;
	// 			views[k][j]=true;
	// 		}
	// 	}
	// 	else if(c=='v')
	// 	{
	// 		for(int k=i+1;k<h;k++)
	// 		{
	// 			if(a[k][j]!='.')break;
	// 			views[k][j]=true;
	// 		}
	// 	}
	// }

    int sx, sy, gx, gy;

    rep(i,h) {
        rep(j,w) {
            if(a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if(a[i][j] == 'G') {
                gx = i;
                gy = j;
            }
            // cout << a[i][j]s;
        }
        // cout << endl;
    }

    // vector<vector<int>> visited(h, vector<int>(w, INF));

    int ans = bfs(sx, sy, gx, gy, a, w, h, views);

    cout << ans << endl;

    // if(visited[gx][gy] == INF) {
    //     cout << -1 << endl;
    // }else{
    //     cout << visited[gx][gy] << endl;
    // }

    return 0;
}
