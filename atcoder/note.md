ABC113
c: 0埋め、stringstream;

ABC190
c: bit
d: 数学的なやつ
e: 巡回セールスマン問題、BFSによる無向グラフ内の最短経路の導出
f: BIT、転倒数、fenwick_tree

ABC191
c: 自己交叉のないn角形
d: sqrtは精度悪い
e: ダイクストラ法、有向グラフ、最短経路
f: gcdとmin -std=c++17 部分集合内の最大公約数、連想配列

ABC192
d: n進数、llを超えないように計算する、二分探索
e: ダイクストラ、無向グラフ
f: dp

ABC193
c: 連想配列
d: 確率計算

ABC194
c: 2乗計算の式変形、連想配列、
```math
\sum_{i=2}^{n} \sum_{j=i}^{i-1}(A_i - A_j)^2
=
n\sum_{i=1}^{n}A_i^2 - (\sum_{i=1}^{n}A_j)^2
```

d: 確率pの事象が出るまで行うときの試行回数の期待値は1/p
e: windowずらし

ABC195
d: 貪欲法 pairのソート
e: dp[i][j]: i文字目まで決まっていて、mod7がjの時の勝敗 バックトラッキング

ABC196
d: dfs全探索
e: 数学的処理
f: 高速フーリエ変換

ABC197
e: 2つに分かれるdp

ABC198
f: 全探索, 階上の計算, 10!*10ぐらいは5秒で終わる
e: dfs典型, 入るときに足す、戻るときに引く

ABC200
d: 部分和、最後にバックトラッキング、経路復元

ABC201
d: dp ゲーム系は最後から戻るDPになりがち。
e: xorは2回付すと戻る。桁ごとに分けて考える。木のxorは根を一つ決めて、根からのxorで考える。

ABC205
d: 二分探索 lower_bound URL:https://qiita.com/ganariya/items/33f1326154b85db465c3

ABC206
d: Union Find

ABC202
d: combination long long の範囲

ABC204
d: 部分和のdp

ABC208
d: ワーシャルフロイド

ABC210
d: 絶対値を外して数式に落とし込む

ABC214
d: UNION FINDでコストの小さい辺から繋げていく。

ABC215
e: bitDP

ABC216
d:
upper_bound ある値より大きい最小の要素の検索
lower_bound ある値以上の最小の要素の検索

ABC223
d: トポロジカルソート

ABC224
f: seg_tree ある区間のモノイド計算ができる。点と点の交換ができる。O(lgn)

ARC112
a: A-B=Cを満たす組み合わせ　表を作ろう
b: 

ARC114
a: bit全探索
b: 循環するのを特定

ARC116
a,b,c: 数え上げ、一文字固定する、規則性を見つける
c: エラトステネスの篩、combination前処理(MODの計算込)

DP
a: 1次元配列　渡すDPでももらうDPでも
b: 1次元配列  渡すDPの方が楽そう

d: 典型的DP　ナップサック問題dp[item][cost]
e: 典型的DP　ナップサック問題dp[item][value] 
f: LCS dp[i][j]: s_iまでとt_jまでの最長共通部分列 string vectorのswapは時間かかる？
g: DAG(非巡回有向グラフ) メモ化dfs