class Solution {
public:
    bool dfs(int r, int c, int index,
             vector<vector<char>>& board, string& word) {

        // All characters matched
        if (index == word.size()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        // Check boundaries and current character
        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != word[index]) {
            return false;
        }

        // Save character and mark cell as visited
        char ch = board[r][c];
        board[r][c] = '#';

        // Explore four directions
        bool found = dfs(r + 1, c, index + 1, board, word) ||
                     dfs(r - 1, c, index + 1, board, word) ||
                     dfs(r, c + 1, index + 1, board, word) ||
                     dfs(r, c - 1, index + 1, board, word);

        // Backtrack: restore original character
        board[r][c] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, board, word)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};