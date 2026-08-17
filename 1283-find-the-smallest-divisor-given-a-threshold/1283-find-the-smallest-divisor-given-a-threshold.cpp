class Solution {
public:

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = 0;

            for (int num : nums) {
                sum += (num + mid - 1) / mid;
            }

            if (sum <= threshold) {
                // mid works
                // Try smaller divisor
                high = mid - 1;
            }
            else {
                // mid does not work
                // Need bigger divisor
                low = mid + 1;
            }
        }

        return low;
    }
};