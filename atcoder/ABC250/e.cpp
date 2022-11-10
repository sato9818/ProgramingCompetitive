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
    vector<int> a(n), b(n);
    vector<P> range(n);
    
    rep(i,n){
        cin >> a[i];
    }

    rep(i,n){
        cin >> b[i];
    }

    set<int> sa, sb, dif;

    int j = 0;
    rep(i,n){
        if(sa.find(a[i]) != sa.end()){
            range[i] = range[i-1];
            continue;
        }
        sa.insert(a[i]);
        if(dif.find(a[i]) != dif.end()){
            dif.erase(a[i]);
        }
        int left = -1;
        while(true){
            // cout << i << ":" << j << ":" << sa.size() << ":"<< sb.size() << ":" << dif.size() <<endl;
            if(sa.size() == sb.size() && dif.size() == 0){
                if(left == -1){
                    left = j-1;
                }
                if(j >= n || sb.find(b[j]) == sb.end()){
                    range[i] = P(left,j-1);
                    // cout << range[i].first << ":" << range[i].second << endl;
                    break;
                }
            }else{
                if(j >= n || sa.size() <= sb.size()){
                    range[i] = P(-1, -1);
                    break;
                }
            }
            sb.insert(b[j]);
            
            if(sa.find(b[j]) == sa.end()){
                dif.insert(b[j]);
            }
            j++;
        }
        
    }

    int q;
    cin >> q;

    rep(i,q){
        int x,y;
        cin >> x >> y;
        if(range[x-1].second == -1){
            cout << "No" << endl;
        }else{
            if(range[x-1].first <= y-1 && y-1 <= range[x-1].second){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    // for(auto p : range){
    //     cout << p.first << ":" << p.second << endl;
    // }

    // 1 2 3 4 5 
    // 1 3 3 5 5
    
    return 0;
}
