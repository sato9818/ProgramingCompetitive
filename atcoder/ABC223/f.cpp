#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

template <typename T>
struct RMQ {
    const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, INF) { // 葉の数は 2^x の形
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;  // parent
            dat[i] = T(dat[i * 2 + 1].first + dat[i * 2 + 2].first, min(dat[i * 2 + 1].second, dat[i * 2 + 1].first + dat[i * 2 + 2].second));
        }
    }
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return T(vl.first + vr.first, min(vl.second, vl.first + vr.second));
        }
    }
};

int main() {
  int n,q;
  string s;
  cin >> n >> q;
  cin >> s;

  RMQ<P> seg(n);
  
  rep(i,s.size()){
    if(s[i] == '('){
      seg.update(i,P(1,0));
    }else{
      seg.update(i,P(-1,-1));
    }
  }

  // rep(i,seg.dat.size()){
  //   cout << seg.dat[i].first << " " << seg.dat[i].second << endl;
  // }

  for(int i=0;i<q;i++){
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    r--;
    
    if(t == 1){
      swap(s[l],s[r]);
      if(s[l] == '('){
        seg.update(l,P(1,0));
      }else{
        seg.update(l,P(-1,-1));
      }
      if(s[r] == '('){
        seg.update(r,P(1,0));
      }else{
        seg.update(r,P(-1,-1));
      }
    }else{
      P ans = seg.query(l,r+1);
      // cout << ans.first << endl;
      // cout << ans.second << endl;
      if(ans.first == 0 && ans.second == 0){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
  }
  
  return 0;
}
