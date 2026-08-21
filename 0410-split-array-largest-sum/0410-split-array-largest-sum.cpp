class Solution {
public:

    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int num : nums) {

            if (currentSum + num > maxSum) {
                // Start a new subarray
                subarrays++;
                currentSum = num;

                // More than k subarrays required
                if (subarrays > k)
                    return false;
            }
            else {
                currentSum += num;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {

        long long left = 0;
        long long right = 0;

        // Search range:
        // left  = maximum element
        // right = total sum
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }

        // Binary search for minimum possible maximum sum
        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                // mid is possible
                // Try smaller
                right = mid;
            }
            else {
                // mid is impossible
                // Need larger
                left = mid + 1;
            }
        }

        return (int)left;
    }
};