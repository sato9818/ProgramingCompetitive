#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

// stable
// online: you do not need to see the whole array

vector<int> insertion(vector<int> arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        int ele = arr[i];
        int j = i-1;
        while(j >= 0){
            if(arr[j] > ele){
                arr[j+1] = arr[j];
                j--;
            }else{
                break;
            }
        }
        arr[j+1] = ele;
    }
    return arr;
}

int main() {
    vector<int> arr = {1,3,4,1,6,8,23,3};
    arr = insertion(arr);
    rep(i,arr.size()){
        cout << arr[i] << " ";
    }

    return 0;
}
