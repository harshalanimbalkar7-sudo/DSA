class Solution {
public:

    void solve(int index, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Reached the end
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Include nums[index]
        current.push_back(nums[index]);

        solve(index + 1, nums, current, ans);

        // Backtrack
        current.pop_back();

        // Choice 2: Don't include nums[index]
        solve(index + 1, nums, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};