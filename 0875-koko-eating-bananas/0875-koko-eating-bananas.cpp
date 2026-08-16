class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + k - 1) / k;

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid)) {
                // k works, try a smaller speed
                high = mid - 1;
            }
            else {
                // k is too slow, increase speed
                low = mid + 1;
            }
        }

        return low;
    }
};