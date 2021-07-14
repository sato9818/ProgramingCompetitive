#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int A,B,H,M;
    cin >> A >> B >> H >> M;

    double L = 30 * H + 0.5 * M;
    int S = 6 * M;
    double sita = abs(L - S);
    double C = sqrt((double)A*A + B*B - 2*A*B*cos((double)sita / 180 * acos(-1)));
    
    cout << fixed << setprecision(15) << C<< endl;
	return 0;
}
