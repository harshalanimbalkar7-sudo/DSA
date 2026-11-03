class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters from left
            if (!isalnum(s[left])) {
                left++;
            }

            // Skip non-alphanumeric characters from right
            else if (!isalnum(s[right])) {
                right--;
            }

            else {
                // Compare lowercase characters
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }
};