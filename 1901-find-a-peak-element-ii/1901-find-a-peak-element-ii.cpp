class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Find maximum element in column mid
            int maxRow = 0;

            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int left = (mid - 1 >= 0)
                       ? mat[maxRow][mid - 1]
                       : -1;

            int right = (mid + 1 < n)
                        ? mat[maxRow][mid + 1]
                        : -1;

            int current = mat[maxRow][mid];

            // Current element is a peak
            if (current > left && current > right) {
                return {maxRow, mid};
            }

            // Left side is bigger
            else if (left > current) {
                high = mid - 1;
            }

            // Right side is bigger
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};