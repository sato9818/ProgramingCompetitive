#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <typename T>
struct RMQ {
    // const T INF = numeric_limits<T>::max();
    int n;         // 葉の数
    vector<T> dat; // 完全二分木の配列
    RMQ(int n_) : n(), dat(n_ * 4, make_pair(100001,-1)) { // 葉の数は 2^x の形
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
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2], [](P a, P b){
              return a.first<b.first || (a.first == b.first && a.second>b.second);
            });
        }
    }
    // the minimum element of [a,b)
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return make_pair(100001,-1);
        } else if (a <= l && r <= b) {
            return dat[k];
        } else {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr, [](P a, P b){
              return a.first<b.first || (a.first == b.first && a.second>b.second);
            });
        }
    }
    void pr(){
      rep(i,dat.size()){
        // int ind = i + n - 1;
        cout << dat[i].first << endl;  
      }
    }
};

int main() {
  int n, k;
  cin >> n >> k;
  RMQ<P> t(n);
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    t.update(i,make_pair(a[i],i));
  }

  rep(i,n){
    int r;
    if(k+i+1 > n){
      r = n;
    }else{
      r = k+i+1;
    }
    P mi = t.query(i,k+i+1);
    if(mi.second != i && a[i] > a[mi.second]){
      swap(a[i],a[mi.second]);
      break;
    }
  }

  rep(i,n){
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}