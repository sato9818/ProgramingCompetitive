#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string dp[3001][3001];

int main() {
    string s,t;
    cin >> s;
    cin >> t;
    int tlen = t.length();
    int slen = s.length();
    // vector< vector<string> > dp(slen+1, vector<string>(tlen+1));
    // string dp[slen+1][tlen+1];
    // vector< vector<int> > dp(N);

    
    
    rep(i,tlen+1){
        dp[0][i] = "";
    }
    rep(i,slen+1){
        dp[i][0] = "";
    }

    rep(i,slen){
        rep(j,tlen){
            if(s.at(i) == t.at(j)){
                dp[i+1][j+1] = dp[i][j] + s.at(i);
            }else{
                if(dp[i+1][j].length() > dp[i][j+1].length()){
                    dp[i+1][j+1] = dp[i+1][j];
                }else{
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }      
    }
    
    cout << dp[slen][tlen] << endl;
    
    return 0;
}