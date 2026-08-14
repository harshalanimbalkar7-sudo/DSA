class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums[0];

        while (low <= high) {

            int mid = low + (high - low) / 2;

            ans = min(ans, nums[mid]);

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }

            // Right half is sorted
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};