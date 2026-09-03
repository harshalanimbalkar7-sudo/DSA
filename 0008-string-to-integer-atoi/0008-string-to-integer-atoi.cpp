class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // 3. Convert digits
        long long ans = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before adding digit
            if (ans > (INT_MAX - digit) / 10) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return sign * ans;
    }
};