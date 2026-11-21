class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int count = 0;
        int oddCount = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Count odd numbers
            if (nums[right] % 2 != 0) {
                oddCount++;
            }

            // Shrink window if odd count exceeds k
            while (oddCount > k) {
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            // Count valid subarrays
            count += right - left + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};