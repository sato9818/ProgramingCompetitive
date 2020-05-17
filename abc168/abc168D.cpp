#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    int N,M;
    vector< vector<int> > root(200001);
    int cnt[100001] = {0};
    int mark[100001] = {0};
    cin >> N >> M;
    rep(i,M) {
        int A,B;
        cin >> A >> B;
        root[A].push_back(B);
        cnt[A]++;
        root[B].push_back(A);
        cnt[B]++;
    }
    
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int room = que.front(); // 先頭要素を参照する
        que.pop(); // 先頭要素を削除
        rep(j,cnt[room]){
            if(mark[root[room][j]] == 0){
                mark[root[room][j]] = room;
                que.push(root[room][j]);
            }
        }
    }

    for(int i=2;i<N+1;i++){
        if(mark[i] == 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i=2;i<N+1;i++){
        cout << mark[i] << endl;
    }
    
	return 0;
}