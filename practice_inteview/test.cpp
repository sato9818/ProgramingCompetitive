#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;
#include <stdlib.h>

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;



bool isAnagram(string s, string t) {
    unordered_map<int, int> char_cnt;
    wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
    wstring m_s = converter.from_bytes(s);
    wstring m_t = converter.from_bytes(t);
    for(auto ch : m_s){
        char_cnt[ch]++;
    }
    int valid_count = 0;
    
    for(auto ch : m_t){
        if(char_cnt.count(ch)){
            char_cnt[ch]--;
            if(char_cnt[ch] == 0){
                valid_count++;
            }else if(char_cnt[ch] < 0){
                return false;
            }
        }else{
            return false;
        }
    }
    return valid_count == char_cnt.size();
}

int main() {
    cout << isAnagram("cat", "tac") << endl;
    cout << isAnagram("アイウエオ", "オエウイ") << endl;
    // cout << uni << endl;

    return 0;
}
