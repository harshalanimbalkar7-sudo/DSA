class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int sum = 0;

        // Take first k cards from the left
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }

        int maxSum = sum;

        // Replace left cards with right cards
        for (int i = 0; i < k; i++) {
            sum -= cardPoints[k - 1 - i];
            sum += cardPoints[n - 1 - i];

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};