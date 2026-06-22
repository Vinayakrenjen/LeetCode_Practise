class Solution {
public:
    int count = 0;
    void nqueen(int col, int n, vector<string>& board,
                vector<int>& leftrow, vector<int>& upperdiag,
                vector<int>& lowerdiag) {
        if (col == n) {
            count++;
            cout<<count << " ";
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && upperdiag[n - 1 + col - row] == 0 &&
                lowerdiag[col + row] == 0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiag[n - 1 + col - row] = 1;
                lowerdiag[col + row] = 1;
                nqueen(col + 1, n, board, leftrow, upperdiag, lowerdiag);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperdiag[n - 1 + col - row] = 0;
                lowerdiag[col + row] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftrow(n, 0), upperdiag(2 * n - 1, 0),
            lowerdiag(2 * n - 1, 0);
        //int count = 0;
        nqueen(0, n, board, leftrow, upperdiag, lowerdiag);
        return count;
    }
};