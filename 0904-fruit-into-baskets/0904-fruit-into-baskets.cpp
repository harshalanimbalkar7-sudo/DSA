class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxLen = 0;

        unordered_map<int, int> mp;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit to the basket
            mp[fruits[right]]++;

            // If more than 2 fruit types, shrink window
            while (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            // Update maximum fruits collected
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};