class Solution {
public:
    bool isAnagram(string s, string t) {

        // Different lengths cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        int freq[26] = {0};

        // Count characters from s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Remove characters using t
        for (char ch : t) {
            freq[ch - 'a']--;
        }

        // Check if all frequencies are zero
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};