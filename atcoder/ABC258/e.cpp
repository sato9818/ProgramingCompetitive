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
    int n, q, x;
    cin >> n >> q >> x;
    vector<ll> w(n), potatos(n);
    rep(i,n) cin >> w[i];

    ll sum_potatos = 0;
    rep(i,n){
        sum_potatos += w[i];
    }

    int quantity = x / sum_potatos;
    int reminder = x % sum_potatos;
    
    int j = 0;
    ll weight = 0;
    rep(i,n){
        while(weight < reminder){
            weight += w[j % n];
            j++;
        }
        potatos[i] = j-i;
        weight -= w[i];
    }

    // rep(i,n){
    //     cout << potatos[i] << endl;
    // }

    map<int,int> loop_detector;

    int pos = 0;
    int cnt = 0;
    vector<int> indices;
    // cout << pos << endl;
    while(loop_detector.count(pos) == 0){
        indices.push_back(pos);
        loop_detector[pos] = cnt;
        cnt++;
        pos = (potatos[pos] + pos) % n;
        // cout << pos << endl;
    }

    int loop_length = cnt - loop_detector[pos];
    // cout << "loop_length: " << loop_length << endl;
    // vector<int> loop(loop_length);
    // rep(i,loop_length){
    //     loop[i] = pos;
    //     pos = (potatos[pos] + pos) % n;
    //     cout << loop[i] << endl;
    // }

    rep(i,q){
        ll k;
        cin >> k;
        k--;
        // cout << (loop_length + k - loop_detector[pos]-1) % loop_length << endl;
        // cout << loop[(loop_length + k - loop_detector[pos]-1) % loop_length] << endl;
        if(k < loop_detector[pos]){
            cout << potatos[indices[k]] + quantity * n << endl;
        }else{
            cout << potatos[indices[(k - loop_detector[pos]) % loop_length + loop_detector[pos]]] + quantity * n << endl;
        }
       
    }

    return 0;
}