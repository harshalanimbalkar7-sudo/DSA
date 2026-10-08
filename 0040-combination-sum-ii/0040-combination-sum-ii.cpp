class Solution {
public:

    void solve(int index, vector<int>& candidates, int target,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // No more elements or target exceeded
        if (index == candidates.size() || target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate numbers at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no further number can work
            if (candidates[i] > target)
                break;

            // Take this number
            current.push_back(candidates[i]);

            // i + 1 because each number can be used only once
            solve(i + 1, candidates, target - candidates[i],
                  current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, current, ans);

        return ans;
    }
};