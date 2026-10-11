class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Store the current subset
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Take the current element
            current.push_back(nums[i]);

            // Move to the next index
            solve(i + 1, nums, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        // Sort to bring duplicates together
        sort(nums.begin(), nums.end());

        solve(0, nums, current, ans);

        return ans;
    }
};