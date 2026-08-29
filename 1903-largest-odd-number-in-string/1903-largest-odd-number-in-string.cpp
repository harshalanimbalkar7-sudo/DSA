class Solution {
public:
    string largestOddNumber(string num) {

        // Start from the last digit
        for (int i = num.length() - 1; i >= 0; i--) {

            int digit = num[i] - '0';

            // Check if digit is odd
            if (digit % 2 == 1) {

                // Return everything from beginning to i
                return num.substr(0, i + 1);
            }
        }

        // No odd digit found
        return "";
    }
};