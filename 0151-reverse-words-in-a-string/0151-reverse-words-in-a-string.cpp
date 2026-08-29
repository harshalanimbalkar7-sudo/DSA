class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        int i = s.length() - 1;

        while (i >= 0) {

            // Skip spaces
            while (i >= 0 && s[i] == ' ') {
                i--;
            }

            if (i < 0)
                break;

            // Find the end of current word
            int j = i;

            // Move left until we find a space
            while (j >= 0 && s[j] != ' ') {
                j--;
            }

            // Add space before every word except the first
            if (!ans.empty()) {
                ans += ' ';
            }

            // Add the word
            ans += s.substr(j + 1, i - j);

            // Move to the previous word
            i = j - 1;
        }

        return ans;
    }
};