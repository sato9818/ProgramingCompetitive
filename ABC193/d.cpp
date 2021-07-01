#include <bits/stdc++.h>
#include <unordered_set>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int score(string str){
  vector<int> cnt(10, 0);
  rep(i,str.size()){
    cnt[(str[i] - '0')]++;
  }
  int sum = 0;
  rep1(i,cnt.size()){
    int mul = 1;
    rep(j,cnt[i]){
      mul *= 10;
    }
    sum += i * mul;
  }
  return sum;
}

int main() {
  int k;
  string s, t;
  cin >> k;
  cin >> s;
  cin >> t;
  vector<int> cards(10, k);
  int rem_cards = 9 * k - 8;

  rep(i,4){
    cards[s[i]-'0']--;
  }

  rep(i,4){
    cards[t[i]-'0']--;
  }

  double prob = 0;
  rep1(i,10){
    rep1(j,10){
      s[4] = i + '0';
      t[4] = j + '0';
      if(score(s) > score(t)){
        if(i != j){
          prob += ((double)cards[i] / rem_cards) * ((double)cards[j] / (rem_cards - 1));
        }else{
          prob += ((double)cards[i] / rem_cards) * ((double)(cards[j]-1) / (rem_cards - 1));
        }
      }
    }
  }
  
  printf("%f\n", prob);
  return 0;
}