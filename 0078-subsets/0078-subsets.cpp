class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Base case: all elements have been considered
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Take the current element
        current.push_back(nums[index]);

        solve(index + 1, nums, current, ans);

        // Backtrack: remove the current element
        current.pop_back();

        // Choice 2: Do not take the current element
        solve(index + 1, nums, current, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};