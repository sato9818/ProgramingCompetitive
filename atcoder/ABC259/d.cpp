#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

struct Circle {
    ll x, y, r;
    Circle(ll x, ll y, ll r): x(x), y(y), r(r) {}
};

int main() {
    int n;
    cin >> n;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    vector<Circle> circles;
    vector<vector<int>> intersected(n);

    rep(i,n){
        int x,y,r;
        cin >> x >> y >> r;
        circles.emplace_back(x,y,r);
    }

    auto is_intersected = [&](Circle circle1, Circle circle2){
        ll dis = (circle1.x - circle2.x) * (circle1.x - circle2.x) + (circle1.y - circle2.y) * (circle1.y - circle2.y);
        ll r2 = (circle1.r + circle2.r) * (circle1.r + circle2.r);
        ll difr2 = (circle1.r - circle2.r) * (circle1.r - circle2.r);
        return difr2 <= dis && r2 >= dis;
    };

    rep(i,n){
        Circle circle1 = circles[i];
        for(int j = i+1;j<n;j++){
            Circle circle2 = circles[j];
            if(is_intersected(circle1, circle2)){
                intersected[i].push_back(j);
                intersected[j].push_back(i);
            }
        }
    }

    int start, end;
    rep(i,n){
        Circle circle = circles[i];
        if((sx - circle.x) * (sx - circle.x) + (sy - circle.y) * (sy - circle.y) == circle.r * circle.r){
            start = i;
            break;
        }
    }
    rep(i,n){
        Circle circle = circles[i];
        if((tx - circle.x) * (tx - circle.x) + (ty - circle.y) * (ty - circle.y) == circle.r * circle.r){
            end = i;
            break;
        }
    }

    queue<int> q;
    q.push(start);

    vector<int> visited(n,0);
    visited[start] = 1;
    while(!q.empty()){
        int idx = q.front(); q.pop();
        if(idx == end){
            cout << "Yes" << endl;
            return 0;
        }
        for(auto next : intersected[idx]){
            if(!visited[next]){
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
