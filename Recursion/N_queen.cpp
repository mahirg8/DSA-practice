// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperD, vector<int> &lowerD, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(leftRow[row]==0 && upperD[n-1 + col-row]==0 && lowerD[row+col] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperD[n-1 + col-row]=1;
                lowerD[row+col]=1;
                solve(col+1, board, ans, leftRow, upperD, lowerD, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperD[n-1 + col-row]=0;
                lowerD[row+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        vector<int> leftRow(n,0), upperD(2*n-1, 0), lowerD(2*n-1,0);
        solve(0, board, ans, leftRow, upperD, lowerD, n);
        return ans; 
    }
};