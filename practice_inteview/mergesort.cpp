#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// unstable
// online: you do not need to see the whole array

void merge(vector<int>& arr, int s, int m, int e) {
    vector<int> left, right;
    
    for(int i=s;i<=m;i++){
        left.push_back(arr[i]);
    }
    for(int i=m+1;i<=e;i++){
        right.push_back(arr[i]);
    }
    
    int li = 0, ri = 0;
    int i = s;
    while(li != left.size() || ri != right.size()){
        if(li == left.size()){
            arr[i++] = right[ri];
            ri++;
            continue;
        }
        if(ri == right.size()){
            arr[i++] = left[li];
            li++;
            continue;
        }
        if(left[li] < right[ri]){
            arr[i++] = left[li];
            li++;
        }else{
            arr[i++] = right[ri];
            ri++;
        }
    }
}

void merge_sort(vector<int>& arr, int s, int e){
    if (s >= e) return;
  
    int mid = (s + e) / 2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

int main() {
    vector<int> arr = {1,3,4,1,6,8,23,3};
    merge_sort(arr, 0, arr.size()-1);
    rep(i,arr.size()){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
