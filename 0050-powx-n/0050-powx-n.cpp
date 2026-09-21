class Solution {
public:
    double myPow(double x, int n) {
        
        long long power = n;

        // Handle negative power
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double ans = 1.0;

        while (power > 0) {
            
            // If power is odd
            if (power % 2 == 1) {
                ans = ans * x;
            }

            // Square x
            x = x * x;

            // Divide power by 2
            power = power / 2;
        }

        return ans;
    }
};