class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            // Remove intervals that do not overlap
            if (!pq.empty() && pq.top() < start) {
                pq.pop();
            }

            // Add the current interval's ending time
            pq.push(end);
        }

        return pq.size();
    }
};