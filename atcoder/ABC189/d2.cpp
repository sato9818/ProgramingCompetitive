#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T>
void print(const char* name, const std::vector<T>& v)
{
  std::cout << name << " : {";

  for (const T& x : v) {
    std::cout << x << " ";
  }

  std::cout << "}" << std::endl;
}

int main() {
    int N;
    cin >> N;
    vector<string> s(N);
    vector<ll> dp(2, 1);
    
    rep(i, N){
        cin >> s[i];
    }
    rep(i,N){
        vector<ll> dpn(2, 0);

        rep(j,2){
            rep(x,2){
                int index;
                if(s[i] == "AND"){
                    index = j && x;
                }else{
                    index = j || x;
                }
                dpn[index] += dp[j];
            }
        }
        dp.swap(dpn);
        if(i == N-1){
            cout << dp[1] << endl;
        }
    }
    

    return 0;
}