class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,
                                  vector<int>& nums2) {

        // Always make nums1 the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int leftSize = (m + n + 1) / 2;

        while (low <= high) {

            // Partition nums1
            int i = low + (high - low) / 2;

            // Partition nums2
            int j = leftSize - i;

            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == m) ? INT_MAX : nums1[i];

            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Odd number of elements
                if ((m + n) % 2 == 1) {
                    return max(l1, l2);
                }

                // Even number of elements
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // We took too many elements from nums1
            if (l1 > r2) {
                high = i - 1;
            }

            // We took too few elements from nums1
            else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};