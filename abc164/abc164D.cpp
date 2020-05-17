#include <iostream>
using namespace std;

int cnt[2019];
int ans = 0;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    int t = 0;
    int p = 1;
    cnt[0] = 1;
    for(int i=0;i<s.length();i++){
        t = t + p * (s[i] - '0');
        t = t % 2019;
        ans += cnt[t];
        cnt[t]++;
        p *= 10;
        p = p % 2019;
    }
    cout << ans << endl;
	return 0;
}