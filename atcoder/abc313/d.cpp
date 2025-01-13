#include <bits/stdc++.h>
#include <atcoder/all>
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

void print(set<int>& s, int last) {
    cout << "? ";
    for(auto x : s) {
        cout << x << " ";
    }
    cout << last << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    vector<set<int>> cands(2,set<int>{});

    rep(i,k-1){
        s.insert(i+1);
    }
    for(int i=k-1;i<n;i++) {
        print(s, i+1);
        int ans;
        cin >> ans;
        cands[ans].insert(i+1);
        cands[ans].insert(i+1);
    }

    int num = k-1;
    int index = n;
    while(num > 0) {
        s.erase(num);
        s.insert(index);
        print(s, index-1);
        int ans;
        cin >> ans;
        int flag = 0;
        if(cands[ans].find(index-1) == cands[ans].end()) {
            flag = 1;
        }
        
        for(int i = num;i<index-1;i++){
            print(s, i);
            int x;
            cin >> x;
            // if(!flag) {
            //     cands[x].insert(i);
            // } else {
            //     if(x == 0){
            //         cands[1].insert(i);
            //     }else{
            //         cands[0].insert(i);
            //     }
            // }
        }

        num--;
        index--;
    }

    cout << "!";

    rep(i,n) {
        cout << " 1";
    }
    cout << endl;

    // int cnt = 0;
    // cout << "?";
    // for(auto x:cands[0]){
    //     cout << " " << x;
    //     cnt++;
    //     if(cnt == k){
    //         cout << endl;
    //         int ans;
    //         cin >> ans;
    //         if(ans == 0) {
    //             cout << "!";
    //             rep(i,n) {
    //                 if(cands[0].find(i+1) != cands[0].end()){
    //                     cout << " 0"; 
    //                 }else{
    //                     cout << " 1";
    //                 }
    //             }
    //         } else {
    //             cout << "!";
    //             rep(i,n) {
    //                 if(cands[1].find(i+1) != cands[1].end()){
    //                     cout << " 0"; 
    //                 }else{
    //                     cout << " 1";
    //                 }
    //             }
    //         }
    //         cout << endl;
    //         return 0;
    //     }
    // }
    
    // for(auto x:cands[1]){
    //     cout << " " << x;
    //     cnt++;
    //     if(cnt == k){
    //         cout << endl;
    //         int ans;
    //         cin >> ans;
    //         if(cands[0].size() % 2 == 0){
    //             if(ans == 0) {
    //                 cout << "!";
    //                 rep(i,n) {
    //                     if(cands[1].find(i+1) != cands[1].end()){
    //                         cout << " 0"; 
    //                     }else{
    //                         cout << " 1";
    //                     }
    //                 }
    //             } else {
    //                 cout << "!";
    //                 rep(i,n) {
    //                     if(cands[0].find(i+1) != cands[0].end()){
    //                         cout << " 0"; 
    //                     }else{
    //                         cout << " 1";
    //                     }
    //                 }
    //             }
    //         }else{
    //             if(ans == 0) {
    //                 cout << "!";
    //                 rep(i,n) {
    //                     if(cands[0].find(i+1) != cands[0].end()){
    //                         cout << " 0"; 
    //                     }else{
    //                         cout << " 1";
    //                     }
    //                 }
    //             } else {
    //                 cout << "!";
    //                 rep(i,n) {
    //                     if(cands[1].find(i+1) != cands[1].end()){
    //                         cout << " 0"; 
    //                     }else{
    //                         cout << " 1";
    //                     }
    //                 }
    //             }
    //         }
    //         cout << endl;
    //         return 0;
    //     }
    // }

    // for(auto x : cands[0]){
    //     cout << x << " ";
    // }
    // cout << endl;

    // for(auto x : cands[1]){
    //     cout << x << " ";
    // }
    // cout << endl;
    

    return 0;
}

// 1 0 0 1 1 0
// 1 2 3 4 5 6
// 1 2 3 4 5 -> 1
// 1 2 3 4 6 -> 0
// 1 2 3 5 6 -> 0
// 1 2 4 5 6 -> 1
// 1 3 4 5 6 -> 1
// 2 3 4 5 6 -> 0

// 1 0 1 1 0


