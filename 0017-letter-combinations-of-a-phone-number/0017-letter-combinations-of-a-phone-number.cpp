class Solution {
public:
    void solve(int index, string& digits,
               vector<string>& mapping,
               string& current,
               vector<string>& ans) {

        // All digits have been processed
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        // Get letters for the current digit
        string letters = mapping[digits[index] - '0'];

        // Try every letter for this digit
        for (char ch : letters) {
            current.push_back(ch);

            solve(index + 1, digits, mapping, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty()) {
            return ans;
        }

        vector<string> mapping = {
            "",     "",     "abc",  "def",
            "ghi",  "jkl",  "mno",  "pqrs",
            "tuv",  "wxyz"
        };

        string current = "";

        solve(0, digits, mapping, current, ans);

        return ans;
    }
};