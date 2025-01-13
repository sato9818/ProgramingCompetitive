#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
using PP = pair<P, int>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

int get_dist(P p1, P p2, vector<string> &s, int h, int w){
    vector<int> xi = {1,0,-1,0};
    vector<int> yi = {0,1,0,-1};
    queue<PP> q;
    vector<vector<int>> visited(h, vector<int>(w, 0));
    q.push(PP(p1, 0));
    while(!q.empty()){
        PP pp = q.front(); q.pop();
        int x = pp.first.first;
        int y = pp.first.second;
        if(x >= h || x < 0 || y >= w || y < 0) continue;
        if(s[x][y] == '#' || visited[x][y]) continue;
        visited[x][y] = 1;
        if(x == p2.first && y == p2.second) return pp.second;
        rep(i,4){
            int nx = x + xi[i];
            int ny = y + yi[i];
            q.push(PP(P(nx, ny), pp.second + 1));
        }
    }
    return -1;
}

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

int main() {
    int h,w, t;
    cin >> h >> w >> t;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<P> snacks;
    rep(i,h)rep(j,w) {
        if(s[i][j] == 'S') snacks.emplace_back(i,j);
    }
    rep(i,h)rep(j,w) {
        if(s[i][j] == 'o') snacks.emplace_back(i,j);
    }
    rep(i,h)rep(j,w) {
        if(s[i][j] == 'G') snacks.emplace_back(i,j);
    }
    int n_snacks = snacks.size();
    vector<vector<int>> dist(n_snacks, vector<int>(n_snacks));

    rep(i,n_snacks)for(int j=i;j<n_snacks;j++){
        int d = get_dist(snacks[i], snacks[j], s, h, w);
        dist[i][j] = dist[j][i] = d;
    }

    vector<vector<ll>> bitdp(1<<n_snacks, vector<ll>(n_snacks,LINF));
    rep(i,n_snacks) if(dist[i][0] != -1) bitdp[(1<<i) | 1][i] = dist[i][0];
    rep(i,1<<n_snacks)rep(j,n_snacks)rep(k,n_snacks){
        if(bitdp[i][j] == LINF || j == k || dist[j][k] == -1) continue;
        bitdp[i | (1 << k)][k] = min(bitdp[i | (1 << k)][k], bitdp[i][j] + dist[j][k]);
    }
    int ans = -1;
    rep(i,1<<n_snacks) {
        if(bitdp[i][n_snacks-1] <= t) {
            ans = max(ans, __builtin_popcount(i) - 2);
        }
    }

    cout << ans << endl;

    return 0;
}
