class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < lastEnd) {
                // Overlapping interval: remove it
                count++;

                // Keep the interval that ends earlier
                lastEnd = min(lastEnd, intervals[i][1]);
            }
            else {
                // No overlap: keep this interval
                lastEnd = intervals[i][1];
            }
        }

        return count;
    }
};