#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

vector<int> z_algorithm(string& str) {
    vector<int> z(str.size());
    if(str.size() == 0){
        return z;
    }
    z[0] = str.size();
    int i=1, j=0;
    int n = str.size();
    while(i < n){
        while(i+j < n && str[i+j] == str[j]) j++;
        z[i] = j;

        if(j == 0){
            i++;
            continue;
        }

        int k = 1;
        while(k < j && z[k] + k < j){
            z[i+k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return z;
}

int main() {
    int n;
    string t;
    cin >> n >> t;
    string s1 = t.substr(0,n);
    string s2 = t.substr(n);
    reverse(s2.begin(), s2.end());
    string str1 = s1 + s2;
    string str2 = s2 + s1;

    vector<int> z1 = z_algorithm(str1);
    vector<int> z2 = z_algorithm(str2);
    z2.push_back(0);

    rep(i,n){
        if(z1[n+i] == n-i && z2[2*n - i] == i){
            string part = str1.substr(n, i);
            reverse(part.begin(), part.end());
            string ans = str1.substr(0,n-i) + part;
            cout << ans << endl;
            cout << n-i << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
