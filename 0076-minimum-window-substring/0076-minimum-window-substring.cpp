class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        if (t.size() > s.size()) return "";

        int freq[128] = {0};

        // Store the frequency of characters in t
        for (char ch : t) {
            freq[ch]++;
        }

        int left = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < n; right++) {

            // If this character is required, decrease count
            if (freq[s[right]] > 0) {
                count--;
            }

            freq[s[right]]--;

            // All required characters are found
            while (count == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the leftmost character
                freq[s[left]]++;

                // If a required character is now missing
                if (freq[s[left]] > 0) {
                    count++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};