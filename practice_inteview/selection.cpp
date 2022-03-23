#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// unstable but it can be made stable
// when you find min index, you swap element all the way from the min index to the i.
// offline

void selection(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        while(min_idx > i){
            swap(arr[min_idx], arr[min_idx - 1]);
            min_idx--;
        }
    }
}

int main() {
    vector<int> arr = {1,3,4,1,6,8,23,3};
    selection(arr);
    rep(i,arr.size()){
        cout << arr[i] << " ";
    }
    return 0;
}
