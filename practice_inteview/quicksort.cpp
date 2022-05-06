#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// unstable
// online: you do not need to see the whole array

int partition(vector<int>& arr, int l, int r) {
    // iより左側はpivot以下
    int i = l;
    int mid = (r+l) / 2;
    int pivot = arr[mid];
    swap(arr[mid], arr[r]);
    for (int j = l; j < r ; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    // exchange
    swap(arr[i], arr[r]);

    return i;
}

void quick_sort(vector<int>& arr, int l, int r) {
    if (l < r) {    
        int q = partition(arr, l, r);
        quick_sort(arr, l, q-1);
        quick_sort(arr, q+1, r);
    }
}  

int main() {
    vector<int> arr = {3,1};
    quick_sort(arr, 0, arr.size()-1);
    rep(i,arr.size()){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
