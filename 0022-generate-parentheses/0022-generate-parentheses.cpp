class Solution {
public:

    void solve(int n, int open, int close,
               string current, vector<string>& ans) {

        // Both types of parentheses are used
        if (open == n && close == n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' if we still have some left
        if (open < n) {
            solve(n, open + 1, close,
                  current + '(', ans);
        }

        // We can add ')' only if it won't make
        // the parentheses invalid
        if (close < open) {
            solve(n, open, close + 1,
                  current + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, 0, 0, "", ans);

        return ans;
    }
};