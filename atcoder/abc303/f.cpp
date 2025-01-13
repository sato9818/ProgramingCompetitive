#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using PP = pair<ll, P>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

ll get_damage(ll rem_turn, ll damage) {
    return damage * rem_turn;
}

bool isOK(ll turn, vector<PP> attacks, ll h){
    ll n = attacks.size();
    int ori_turn = turn;
    rep(i,n){
        if(ori_turn == 9){
            cout << h << endl;
        }
        PP attack = attacks[i];
        ll whole_damage = attack.first;
        ll req_turn = attack.second.first;
        ll damage = attack.second.second;
        if(turn >= req_turn) {
            ll apply_turn = turn - req_turn + 1;
            h -= whole_damage * apply_turn;
            turn -= apply_turn;
        }
        if(ori_turn == 9){
            cout << turn << ":" << h << endl;
        }
        
        if(h <= 0){
            return true;
        }
        while(i-1 < n && get_damage(turn, damage) > get_damage(min(turn, attacks[i+1].second.first), attacks[i+1].second.second)){
            h -= get_damage(turn, damage);
            turn--;
        }
        if(h <= 0){
            return true;
        }
    }
    return false;
}

int main() {
    ll n, h;
    cin >> n >> h;
    vector<PP> attacks(n);

    rep(i,n){
        ll t, d;
        cin >> t >> d;
        attacks[i] = PP(d*t, P(t, d));
    }
    sort(attacks.rbegin(), attacks.rend());

    ll left = 0; 
    ll right = h; 

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;

        if (isOK(mid, attacks, h)) right = mid;
        else left = mid;
    }

    cout << right << endl;

    // for(PP pp : attacks){
    //     cout << pp.first << " " << pp.second.first << " " << pp.second.second << endl;
    // }

    return 0;
}
