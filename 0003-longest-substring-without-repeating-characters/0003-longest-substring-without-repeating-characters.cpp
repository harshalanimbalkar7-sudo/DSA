class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int left = 0;
        int right = 0;
        int maxLen = 0;

        int hash[256] = {0};

        while (right < n) {

            // If character is already present,
            // move left pointer
            if (hash[s[right]] == 1) {
                hash[s[left]] = 0;
                left++;
            }
            else {
                hash[s[right]] = 1;

                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }

        return maxLen;
    }
};