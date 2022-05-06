#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

class BinaryHeap {
public:
    int size;
    vector<int> arr;
    int capacity;

    BinaryHeap(int cap){
        size = 0;
    }

    // O(1)
    int get_min(){
        if(size == 0){
            return -1;
        }
        return arr[0];
    }
    
    // O(log n)
    int extractMin(){
        if(size == 0){
            return -1;
        }
        int ans = arr[0];
        swap(arr[0], arr[size-1]);
        size--;
        heapify(0);
        return ans;
    }

    void heapify(int i){
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int smallest = i;
        if(left < size && arr[left] < arr[smallest]){
            smallest = left;
        }

        if(right < size && arr[right] < arr[smallest]){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // O(log n)
    void insert(int val){
        size++;
        int i = size - 1;
        arr[i] = val;
        while(true){
            if(i == 0){
                break;
            }
            int parent = (i-1)/2;
            if(arr[i] < arr[parent]){
                swap(arr[i], arr[parent]);
                i = parent;
            }else{
                break;
            }
        }
    }

    // O(log n)
    void deleteKey(int i){
        arr[i] = INT_MIN;
        while(true){
            if(i == 0){
                break;
            }
            int parent = (i-1)/2;
            if(arr[i] < arr[parent]){
                swap(arr[i], arr[parent]);
                i = parent;
            }else{
                break;
            }
        }
        extractMin();
    }
};


int main() {
    BinaryHeap bh(10);
    bh.insert(3);
    bh.insert(2);
    bh.deleteKey(1);
    bh.insert(15);
    bh.insert(5);
    bh.insert(4);
    bh.insert(45);
    cout << bh.extractMin() << " ";
    cout << bh.get_min() << endl;
    return 0;
}
