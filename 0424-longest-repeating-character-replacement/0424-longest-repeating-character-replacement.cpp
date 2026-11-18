class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;

        int freq[26] = {0};

        for (int right = 0; right < s.size(); right++) {

            // Increase frequency of current character
            freq[s[right] - 'A']++;

            // Maximum frequency of a character in the window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Characters that need replacement
            int changes = (right - left + 1) - maxFreq;

            // If changes exceed k, shrink window
            if (changes > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};