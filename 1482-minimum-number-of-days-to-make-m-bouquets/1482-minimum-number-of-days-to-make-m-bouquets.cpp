class Solution {
public:

    bool canMake(vector<int>& bloomDay, int m, int k, int day) {

        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= day) {
                // Flower has bloomed
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                // Flower has not bloomed
                flowers = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        // Check if it is impossible
        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                // We can make bouquets
                // Try fewer days
                high = mid - 1;
            }
            else {
                // We cannot make bouquets
                // Need more days
                low = mid + 1;
            }
        }

        return low;
    }
};