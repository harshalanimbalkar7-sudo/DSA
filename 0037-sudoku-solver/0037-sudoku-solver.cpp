
class Solution {
public:
    bool isSafe(vector<vector<char>>& board,
                int row, int col, char num) {

        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == num)
                return false;

            // Check the column
            if (board[i][col] == num)
                return false;

            // Check the 3x3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // Find an empty cell
                if (board[row][col] == '.') {

                    // Try digits 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isSafe(board, row, col, num)) {
                            board[row][col] = num;

                            // Solve the remaining board
                            if (solve(board))
                                return true;

                            // Backtrack if this choice fails
                            board[row][col] = '.';
                        }
                    }

                    // No digit works in this cell
                    return false;
                }
            }
        }

        // No empty cells remain
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
