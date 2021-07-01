#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



int main() {
    int N;
    cin >> N;
    int count = 0;
    vector< vector<int> > p(N, vector<int>(N));
    vector< vector<int> > b(N, vector<int>(N));
    rep(i,ceil((double)N/2)){
        for(int j=i;j<N-i;j++){
            p[i][j] = i;
            p[j][i] = i;
            p[N-i-1][j] = i;
            p[j][N-i-1] = i;
        }
    }
    queue<P> q;

    rep(k,N*N){
        int t;
        cin >> t;
        int i = (t-1) / N;
        int j = (t-1) % N;
        
        count += p[i][j];
            

        b[i][j] = 1;
        q.push(make_pair(i,j));
        // cout << "exit:" << i << j << endl;
        while(!q.empty()){
            P pr = q.front();
            rep(s,4){
                int nx = pr.first + dx[s];
                int ny = pr.second + dy[s];
                if(nx>=0 && nx < N && ny >= 0 && ny < N){
                    if(p[pr.first][pr.second] < p[nx][ny] && b[pr.first][pr.second] == 1){
                        p[nx][ny] = p[pr.first][pr.second];
                        q.push(make_pair(nx,ny));
                        // cout << nx << ny << endl;
                    }else if(p[pr.first][pr.second]+1 < p[nx][ny] && b[pr.first][pr.second] == 0){
                        p[nx][ny] = p[pr.first][pr.second] + 1;
                        q.push(make_pair(nx,ny));
                        // cout << nx << ny << endl;
                    }
                }
            }
            // p[pr.first][pr.second]
            q.pop();
        }
        // rep(x,N){
        //     rep(y,N){
        //         cout << p[x][y];
        //     }
        //     cout << endl;
        // }
    }


    cout << count << endl;
    return 0;
}