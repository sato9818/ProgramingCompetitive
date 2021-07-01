#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string A, B;
    cin >> A >> B;

    int sumA = 0, sumB = 0;

   	rep(i, 3){
        sumA += A[i] - '0';
        sumB += B[i] - '0';
    }

    cout << max(sumA, sumB) << endl;

    return 0;
}