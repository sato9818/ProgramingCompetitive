#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// unstable
// online: you do not need to see the whole array

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;
    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(vector<int>& arr){
    int n = arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {1,3,4,1,6,8,23,3};
    quicksort(arr, 0, arr.size()-1);
    rep(i,arr.size()){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
