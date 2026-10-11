class Solution {
public:
    void solve(int start, int k, int target,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Found a valid combination
        if (current.size() == k) {
            if (target == 0) {
                ans.push_back(current);
            }
            return;
        }

        // Try numbers from start to 9
        for (int i = start; i <= 9; i++) {

            // Remaining sum cannot be negative
            if (i > target)
                break;

            // Choose the number
            current.push_back(i);

            // Next number must be larger
            solve(i + 1, k, target - i, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(1, k, n, current, ans);

        return ans;
    }
};