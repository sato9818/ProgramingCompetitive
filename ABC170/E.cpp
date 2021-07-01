#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, q;
	cin >> n >> q;
	vector<int> a(n), b(n);
 
	vector<multiset<int>> s(200005);
	multiset<int> maxs;
 
	auto getMax = [&](int i) {
		if (s[i].size() == 0) return -1;
		return *s[i].rbegin();
	};
	/* maxs に幼稚園i の 最大スコアを追加 */
	auto addYochien = [&](int i) {
		int x = getMax(i);
		if (x == -1) return;
		maxs.insert(x);
	};
	/* maxs の幼稚園i の 最大スコアを削除 */
	auto delYochien = [&](int i) {
		int x = getMax(i);
		if (x == -1) return;
		maxs.erase(maxs.find(x));
	};
	/* 幼稚園i に幼児のスコアxを追加 */
	auto addEnji = [&](int i, int x) {
		delYochien(i);
		s[i].insert(x);
		addYochien(i);
	};
	/* 幼稚園i から幼児のスコアx を削除*/
	auto delEnji = [&](int i, int x) {
		delYochien(i);
		s[i].erase(s[i].find(x));
		addYochien(i);
	};
 
	rep(i,n) {
		cin >> a[i] >> b[i];
		addEnji(b[i], a[i]);
	}
 
	rep(i,q) {
		int c, d;
		cin >> c >> d;
		--c;
		delEnji(b[c], a[c]);
		b[c] = d;
		addEnji(b[c], a[c]);
		int ans = *maxs.begin();
		printf("%d\n", ans);
	}

    return 0;
}