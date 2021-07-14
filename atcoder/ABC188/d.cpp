#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, C;
    cin >> N >> C;
    vector<P> ac, bc;

    rep(i,N){
        int a,b,c;
        cin >> a >> b >> c;
        ac.push_back(make_pair(a, c));
        bc.push_back(make_pair(b+1, c));
    }
    sort(ac.begin(), ac.end());
    sort(bc.begin(), bc.end());

    int i=0,j=0;
    ll sum = 0, mul = ac[i].second;
    ll now = ac[i].first;
    i++;
    while(i != N || j != N){
        // cout << sum << endl;
        if(i == N){
            if(mul < C){
                sum += (bc[j].first - now) * mul;
            }else{
                sum += (bc[j].first - now) * C;
            }
            mul -= bc[j].second;
            now = bc[j].first;
            j++;
        }else{
            if(ac[i].first < bc[j].first){
                if(mul < C){
                    sum += (ac[i].first - now) * mul;
                }else{
                    sum += (ac[i].first - now) * C;
                }
                mul += ac[i].second;
                now = ac[i].first;
                i++;
            }else if(ac[i].first > bc[j].first){
                if(mul < C){
                    sum += (bc[j].first - now) * mul;
                }else{
                    sum += (bc[j].first - now) * C;
                }
                mul -= bc[j].second;
                now = bc[j].first;
                j++;
            }else{
                if(mul < C){
                    sum += (bc[j].first - now) * mul;
                }else{
                    sum += (bc[j].first - now) * C;
                }
                mul -= bc[j].second;
                mul += ac[i].second;
                now = bc[j].first;
                i++;
                j++;
            }
        }
        
    }

    cout << sum << endl;

    return 0;
}