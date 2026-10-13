
class Solution {
public:
    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& col,
               vector<int>& diagonal1,
               vector<int>& diagonal2) {

        // All rows have a queen
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            // Check column and both diagonals
            if (col[c] == 0 &&
                diagonal1[d1] == 0 &&
                diagonal2[d2] == 0) {

                // Place queen
                board[row][c] = 'Q';
                col[c] = 1;
                diagonal1[d1] = 1;
                diagonal2[d2] = 1;

                // Place queen in next row
                solve(row + 1, n, board, ans,
                      col, diagonal1, diagonal2);

                // Backtrack: remove queen
                board[row][c] = '.';
                col[c] = 0;
                diagonal1[d1] = 0;
                diagonal2[d2] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<int> col(n, 0);
        vector<int> diagonal1(2 * n - 1, 0);
        vector<int> diagonal2(2 * n - 1, 0);

        solve(0, n, board, ans, col, diagonal1, diagonal2);

        return ans;
    }
};
