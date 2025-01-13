#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

bool match(vector<string>& sheet, vector<string>& target) {
    rep(i,30) {
        rep(j,30) {
            if(sheet[i][j] != target[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int ha,wa, hb,wb, hx,wx;
    cin >> ha >> wa;

    vector<string> sheet1(ha);
    vector<vector<string>> targets;
    rep(i,ha) {
        cin >> sheet1[i];
    }
    cin >> hb >> wb;
    vector<string> sheet2(hb);
    rep(i,hb) {
        cin >> sheet2[i];
    }
    cin >> hx >> wx;
    vector<string> sheet3(hx);
    rep(i,hx) {
        cin >> sheet3[i];
    }

    vector<string> sample(30, "..............................");
    vector<string> target = sample;
    rep(k,hx) {
        rep(l,wx) {
            target[10+k][10+l] = sheet3[k][l];
        }
    }

    vector<vector<string>> sheet1s;

    for(int i= 10-ha+1;i<20;i++){
        for(int j=10-wa+1;j<20;j++){
            vector<string> sheet = sample;
            rep(k,ha) {
                rep(l,wa) {
                    sheet[i + k][j+l] = sheet1[k][l];
                }
            }
            sheet1s.push_back(sheet);
        }
    }

    vector<vector<string>> sheet2s;

    for(int i=10-hb+1;i<20;i++){
        for(int j=10-wb+1;j<20;j++){
            vector<string> sheet = sample;
            rep(k,hb) {
                rep(l,wb) {
                    sheet[i+k][j+l] = sheet2[k][l];
                }
            }
            sheet2s.push_back(sheet);
        }
    }

    // cout << sheet1s.size() << " " << sheet2s.size() << endl;

    vector<vector<string>> sheet12s;
    rep(i,sheet1s.size())rep(i2,sheet2s.size()) {
        vector<string> sheet = sample;
        rep(j,30) {
            rep(k,30) {
                if(sheet1s[i][j][k] == '#' || sheet2s[i2][j][k] == '#') {
                    sheet[j][k] = '#';
                }else{
                    sheet[j][k] = '.';
                }
            }
        }
        sheet12s.push_back(sheet);
    }

    rep(j, sheet12s.size()) {
        if(match(sheet12s[j], target)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
