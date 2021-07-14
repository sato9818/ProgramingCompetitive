#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;


  vector<P> s(n),t(n);
  
  rep(i,n){
    int a,b;
    cin >> a >> b;

    s[i] = make_pair(a,b);
  }
  rep(i,n){
    int c,d;
    cin >> c >> d;

    t[i] = make_pair(c,d);
  }
  sort(t.begin(),t.end());

  // for(int q = -30;q<31;q++){
  //   for(int r = -30;r<31;r++){
  //     rep(i,4){
  //       vector<P> tes(n);
  //       rep(j,n){
  //         int x = s[j].first;
  //         int y = s[j].second;
  //         if(i == 0){
  //           tes[j] = make_pair(x + q, y + r);
  //         }else if(i == 1){
  //           tes[j] = make_pair(-y + q, x + r);
  //         }else if(i == 2){
  //           tes[j] = make_pair(-x + q, -y + r);
  //         }else if(i == 3){
  //           tes[j] = make_pair(y + q, -x + r);
  //         }
  //       }
  //       sort(tes.begin(),tes.end());

  //       if(tes == t){
  //         cout << "Yes" << endl;
  //         return 0;
  //       }
  //     }
  //   }
  // }
  const double PI = 3.141592653589793;
  rep(i,360){
    vector<P> tes(n);
    double radian = i * PI / 180.0;
    rep(j,n){
      double x = s[j].first * cos(radian) - s[j].second * sin(radian);
      double y = s[j].first * sin(radian) + s[j].second * cos(radian);
      for(int k = -10;k<11;k++){
        double q = k - x;
        for(int l = -10;l<11;l++){
          double r = l - y;
          rep(m,n){
            double xx = s[m].first * cos(radian) - s[m].second * sin(radian) + q;
            double yy = s[m].first * sin(radian) + s[m].second * cos(radian) + r;
            if(x - (int)x > 0 || y - (int)y > 0){
              break;
            }
            tes[m] = make_pair(xx, yy);
          }
          sort(tes.begin(),tes.end());
          if(tes == t){
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}