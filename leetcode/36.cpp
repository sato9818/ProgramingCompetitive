#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define rep1(i,n) for (int i=1;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, ll>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// [["5","3",".",".","7",".",".",".","."],
// ["6",".",".","1","9","5",".",".","."],
// [".","9","8",".",".",".",".","6","."],
// ["8",".",".",".","6",".",".",".","3"],
// ["4",".",".","8",".","3",".",".","1"],
// ["7",".",".",".","2",".",".",".","6"],
// [".","6",".",".",".",".","2","8","."],
// [".",".",".","4","1","9",".",".","5"],
// [".",".",".",".","8",".",".","7","9"]]

class Solution {
private:
    bool isInt(char c){
        return c >= '1' && c <= '9';
    }
    bool validateVatically(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            vector<int> visited(9, 0);
            for(int j=0;j<9;j++){
                if(!isInt(board[i][j])) continue;
                if(visited[board[i][j]-'1']){
                    return false;
                }
                visited[board[i][j]-'1'] = 1;
            }
        }
        return true;
    }

    bool validateHorizontally(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            vector<int> visited(9, 0);
            for(int j=0;j<9;j++){
                if(!isInt(board[j][i])) continue;
                if(visited[board[j][i]-'1']){
                    return false;
                }
                visited[board[j][i]-'1'] = 1;
            }
        }
        return true;
    }
    // 0: 0,0 1: 0,1 2: 0,2 3: 1,0 4: 1,1 5: 1,2 6: 2,0 7: 2,1 8: 2,2
    bool validateSquare(vector<vector<char>>& board){
        vector<int> visited(9, 0);
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int k=0;k<9;k++){
                    if(!isInt(board[i+k/3][j+k%3])) continue;
                    if(visited[board[i+k/3][j+k%3]-'1']){
                        return false;
                    }
                    visited[board[i+k/3][j+k%3]-'1'] = 1;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(validateHorizontally(board) && validateVatically(board) && validateSquare(board)){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution s;

    cout <<  << endl;
    return 0;
}
