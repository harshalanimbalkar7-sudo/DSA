class Solution {
public:
    vector<vector<bool>> isPal;

    void solve(int start, string& s,
               vector<string>& current,
               vector<vector<string>>& ans) {

        // Entire string has been partitioned
        if (start == s.size()) {
            ans.push_back(current);
            return;
        }

        // Try every possible ending position
        for (int end = start; end < s.size(); end++) {

            // Choose only palindromic substrings
            if (isPal[start][end]) {

                current.push_back(s.substr(start, end - start + 1));

                solve(end + 1, s, current, ans);

                // Backtrack
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();

        // Precompute whether every substring is a palindrome
        isPal.assign(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> current;

        solve(0, s, current, ans);

        return ans;
    }
};