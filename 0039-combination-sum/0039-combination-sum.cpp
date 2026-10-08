class Solution {
public:

    void solve(int index, vector<int>& nums, int target,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Target achieved
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        // No more elements or target became negative
        if (index == nums.size() || target < 0) {
            return;
        }

        // TAKE nums[index]
        if (nums[index] <= target) {
            current.push_back(nums[index]);

            // Same index because we can use the number again
            solve(index, nums, target - nums[index],
                  current, ans);

            // Backtrack
            current.pop_back();
        }

        // NOT TAKE nums[index]
        solve(index + 1, nums, target,
              current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, target, current, ans);

        return ans;
    }
};