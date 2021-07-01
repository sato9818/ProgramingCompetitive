#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N,Q;
    cin >> N >> Q;
    vector<int> a(N+1);
    vector<int> b(N+1);
    multiset<int> maxs;
    vector< multiset<int> > kin(200001);

    auto getMax = [&](int i){
        if(kin[i].size() == 0){
            return -1;
        }else{
            return *kin[i].rbegin();
        }
    };

    rep(i,N){
        cin >> a[i+1] >> b[i+1];
        int mx = getMax(b[i+1]);
        
        if(mx < a[i+1]){
            if(mx != -1)
                maxs.erase(maxs.find(mx));
            maxs.insert(a[i+1]);
        }
        kin[b[i+1]].insert(a[i+1]);
        
    }


    rep(i,Q){
        int c,d;
        cin >> c >> d;

        int mx = getMax(b[c]);
        kin[b[c]].erase(kin[b[c]].find(a[c]));
        if(mx == a[c]){
            maxs.erase(maxs.find(mx));
            int m;
            if((m = getMax(b[c])) != -1){
                maxs.insert(m);
            }
        }
        b[c] = d;
        
        int mx2 = getMax(d);;
        
        if(mx2 < a[c]){
            if(mx2 != -1)
                maxs.erase(maxs.find(mx2));
            maxs.insert(a[c]);
        }
        kin[d].insert(a[c]);
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }
    return 0;
}