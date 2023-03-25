#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

const int MOD = 998244353;
const int INF = 1001001001;
const ll LINF = 1001001001001001001LL;

struct Trie {
    Trie* next[26];
    bool isEnd;
    int cnt;
    Trie() {
        rep(i,26) next[i] = NULL;
        isEnd = false;
        cnt = 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);
    map<string, int> mp;
    rep(i,n) cin >> strs[i];

    Trie* root = new Trie();
    Trie* node = root;
    for(auto str : strs) {
        for(auto ch : str) {
            if(node->next[ch-'a'] == NULL) {
                node->next[ch-'a'] = new Trie();
            }
            
            node = node->next[ch-'a'];
            node->cnt++;
        }
        node = root;
    }
    for(auto str : strs) {
        int ans = 0;
        for(auto ch : str) {
            node = node->next[ch-'a'];
            // cout << ch << ":" << node->cnt << endl;
            if(node->cnt == 1){
                break;
            }
            ans++;
        }
        node = root;
        cout << ans << endl;
    }

    

    return 0;
}
