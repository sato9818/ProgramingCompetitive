#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;;
    cin >> N;
    int cnt = 0;
    int flag = 0;
    rep(i,N){
        int d1,d2;
        cin >> d1;
        cin >> d2;
        if(d1 == d2){
            cnt++;
        }else{
            cnt = 0;
        }
        if(cnt > 2){
            flag = 1;
        }
    }

   	if(flag==1){
       cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
}