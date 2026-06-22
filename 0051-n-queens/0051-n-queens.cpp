class Solution {
public:
    void nqueen(int col, vector<string>&board, vector<vector<string>>&ans,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';

                // Mark the row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                nqueen(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack and remove the queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++){
            board[i] = s;
        }
        vector<int>leftrow(n,0), upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        nqueen(0,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
        return ans;
    }
};