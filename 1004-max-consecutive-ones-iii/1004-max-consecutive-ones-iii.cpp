class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Count zeros in the current window
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If zeros exceed k, shrink the window
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            // Update maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};